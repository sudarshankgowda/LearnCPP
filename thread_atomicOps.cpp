#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>

//std::mutex counterMutex;
std::atomic<int> counter(0);
//int counter(0); //race conditions happen if atomic is disabled and enable this line. This gives undefined value.
void incrementCounter(){
    for(int i = 0; i < 1000000; i++)
    {
        //std::lock_guard<std::mutex> lock(counterMutex);
        counter++;
    }
}
int main()
{
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout<< "Counter value is " << counter << std::endl;
    return 0;
}
