#include<iostream>
#include<mutex>
#include<future>

int computeValue(){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 42;
}

int main()
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread([&promise]{
         int result=computeValue();
         promise.set_value(result);
        }).detach();
    //x.join();
    std::cout << "Waiting for the result ..." << std::endl;

    int result = future.get();
    std::cout<<"Result = "<< result << std::endl;
    return 0;
}
