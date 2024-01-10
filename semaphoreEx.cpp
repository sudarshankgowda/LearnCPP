#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore<int> mySemaphore(1);  // Binary semaphore

int sharedResource = 0;

void incrementSharedResource()
{
    mySemaphore.acquire();
    sharedResource++;
    mySemaphore.release();
}

int main()
{
    const int numThreads = 3;

    std::thread threads[numThreads];

    for (int i = 0; i < numThreads; ++i)
    {
        threads[i] = std::thread(incrementSharedResource);
    }

    for (int i = 0; i < numThreads; ++i)
    {
        threads[i].join();
    }

    std::cout << "Final Shared Resource Value: " << sharedResource << std::endl;

    return 0;
}
