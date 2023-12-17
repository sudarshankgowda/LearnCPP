#include<iostream>
#include<thread>

void threadFunction(int threadId){
    for(int i = 0; i < 5; i++)
    {
        std::cout << "Thread " << threadId << " is running, iteration " << i << std::endl;
    }
}

int main()
{
    std::thread thread1(threadFunction, 1);
    std::thread thread2(threadFunction, 2);

    thread1.join();
    thread2.join();

    std::cout << "Threads have completed their execution " << std::endl;
    return 0;
}
