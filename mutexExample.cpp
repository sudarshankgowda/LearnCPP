#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;
int sharedVariable = 0;

void SharedFunction(int numIncrements)
{
    for(int i = 0; i < numIncrements; i++){
        std::lock_guard<std::mutex> lock(mtx);
        sharedVariable++;
        //lock will be released atomatically lock_guard goes out of scope
    }
}

int main()
{
    int numThreads=9;
    int numIncrements = 100000;
    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; i++)
    {
        threads[i] = std::thread(SharedFunction, numIncrements);
    }

    for(int i = 0; i < numThreads; i++)
    {
        threads[i].join();
    }

    std::cout << "Final Value of sharedVariable : " << sharedVariable << std::endl;
    return 0;
}
