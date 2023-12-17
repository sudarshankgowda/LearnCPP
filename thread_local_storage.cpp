#include<iostream>
#include<thread>
#include<vector>


thread_local int threadId=0;
void printThreadId(){
    std::cout<<"ThreadID : " << threadId << std::endl;
}
int main()
{
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; i++)
    {
        threads.emplace_back([i](){
        threadId = i;
        printThreadId();
        });
    }
    for(auto& t: threads)
    {
        t.join();
    }
    return 0;
}
