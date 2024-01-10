#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int>counter(0);

int functiontoIncreemnt(int numberoftimes)
{
    for(int i = 0; i < numberoftimes; i++)
    {
        counter++;
    }
}

int main()
{
    int numthreads=9;
    std::thread threads[numthreads];
    int numcounter = 100000;

    for(int i = 0; i < numthreads; i++)
    {
        threads[i] = std::thread(functiontoIncreemnt, numcounter);
    }

    for(int i = 0; i < numthreads;i++)
    {
        threads[i].join();
    }

    std::cout << "Count value is : " << counter << std::endl;

    return 0;
}
