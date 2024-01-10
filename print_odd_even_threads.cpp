#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool odd = true;
const int N = 10;
void printnumbers(int start, int step)
{
    for(int i=start; i<=N; i+=step)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]{return (i%2==1)== odd;});
        std::cout << i << " " ;
        odd = !odd;
        cv.notify_one();
    }
}

int main()
{
    std::thread oddthread(printnumbers, 1, 2);
    //std::thread eventhread(printnumbers, 2, 2);

    oddthread.join();
    //eventhread.join();

    return 0;
}
