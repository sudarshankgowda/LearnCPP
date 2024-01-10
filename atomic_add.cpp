#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void incrementCounter(int numberoftimes)
{
    for (int i = 0; i < numberoftimes; ++i)
    {
        counter++;
    }
}

int main()
{
    const int numThreads = 5;
    const int numIncrementsPerThread = 100000;

    std::thread threads[numThreads];

    // Create and start threads
    for (int i = 0; i < numThreads; ++i)
    {
        threads[i] = std::thread(incrementCounter, numIncrementsPerThread);
    }

    // Join threads
    for (int i = 0; i < numThreads; ++i)
    {
        threads[i].join();
    }

    // Print the final counter value
    std::cout << "Final Counter Value: " << counter << std::endl;

    return 0;
}
