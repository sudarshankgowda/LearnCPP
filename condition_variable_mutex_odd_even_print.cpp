#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mtx;
std::condition_variable cv;

bool isOdd=true;
const int N = 10;

void printNumbers(int start, int step)
{
    for(int i = start; i <= N; i+=step)
    {
        std::unique_lock <std::mutex> lock(mtx);
        cv.wait(lock, [&]{ return (i%2 == 1)== isOdd ;});
        std::cout << i << " ";
        isOdd = !isOdd;
        cv.notify_one();
    }
}

int main()
{
    std::thread oddThread(printNumbers, 1, 2);
    std::thread evenThread(printNumbers, 2, 2);
    oddThread.join();
    evenThread.join();
    std::cout << std::endl;
    return 0;
}
