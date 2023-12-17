#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
std::mutex myMutex;

void sharedResourceFunction(int threadId)
{
    std::lock_guard<std::mutex> lock(myMutex);
    std::cout << "Thread : "<< threadId << " is in the critical section." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Thread : " << threadId << " exits the critical section." << std::endl;
}
int main()
{
    const int numThreads = 20;
    std::thread threads[numThreads];

    for(int i = 0; i < numThreads; ++i)
    {
        threads[i]=std::thread(sharedResourceFunction, i+1);
    }

    for( int i = 0; i < numThreads; ++i)
    {
        threads[i].join();
    }
    cout << "Continue with main thread ..." << std::endl;
    return 0;
}
