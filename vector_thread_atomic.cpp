#include<iostream>
#include<thread>
#include<vector>
#include<atomic>

std::atomic<int> counter(0);

void incrementCounter(int iterations)
{
    for(int i = 0; i < iterations; i++)
    {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main()
{
    const int numThreads= 4;
    const int iterationPerThread = 100000;

    std::vector<std::thread> threads;

    for(int i = 0; i < numThreads; i++)
    {
        threads.emplace_back(incrementCounter, iterationPerThread);
    }

    for(auto &thread : threads)
    {
        thread.join();
    }
    std::cout << "Final counter value : " << counter << std::endl;
    return 0;
}
