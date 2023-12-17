#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
std::mutex myMutex;

void sharedThreadFunction(int threadId)
{
    std::lock_guard<std::mutex> lock(myMutex);
    std::cout << "Thread Id : " << threadId << " Entering Critical Section " << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Thread Id : " << threadId << " Exiting the Critical section " << std::endl;
}
int main()
{
    int numofThreads = 50;
    std::thread threads[numofThreads];

    for(int i = 0; i < numofThreads; i++)
    {
        threads[i]=std::thread(sharedThreadFunction, i+1);
    }

    for(int i = 0; i < numofThreads; i++)
    {
        threads[i].join();
    }
    std::cout<< "Continue with main threads ..." << std::endl;
    return 0;
}

