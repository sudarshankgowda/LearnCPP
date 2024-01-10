#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;

void sharedfunction(int threadId)
{
    std::cout << "Started with shared function by threadId : " << threadId << std::endl;
    std::lock_guard<std::mutex> lock(mtx);
    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout << "Operation performed by threadId :" << threadId << std::endl;

}

int main()
{
    int numThreads= 5;
    std::thread threads[numThreads];

    for( int i = 0; i < numThreads; i++)
    {
        threads[i]= std::thread(sharedfunction, i+1);
    }

    for( int i = 0; i < numThreads; i++)
    {
        threads[i].join();
    }
    return 0;

}
