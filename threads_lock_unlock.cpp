#include<iostream>
#include<thread>
#include<mutex>

std::mutex myMutex;

void sharedThreadFunction(int threadId)
{
    std::unique_lock<std::mutex> lock(myMutex);
    std::cout<<"Thread ID : " << threadId << " is inside the critical section " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Thread ID : " << threadId << " exiting from the critical section " << std::endl;
    lock.unlock();
    for( int i = 0; i < 15; i++)
        std::cout<< "Thread Id : " << threadId << " and is after the unlock call " << std::endl;
}

int main()
{
    int numthreads = 50;
    std::thread threads[numthreads];

    for(int i = 0; i < numthreads; ++i )
    {
        threads[i] = std::thread(sharedThreadFunction, i+1);
    }

    for(int i = 0; i < numthreads; ++i)
    {
        threads[i].join();
    }
    std::cout << "Continue with Main function ..." << std::endl;
    return 0;
}
