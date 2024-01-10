#include<iostream>
#include<thread>
#include<future>

void calculatesquare(std::promise<int> & promiseobj, int input)
{
    std::this_thread::sleep_for(std::chrono::seconds(10));

    int result = input*input;

    promiseobj.set_value(result);
}

int main()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();


    std::thread calculateThread(calculatesquare, std::ref(promiseObj), 5);
    std::cout << "Main thread doing some work" << std::endl;

    int result = futureObj.get();
    std::cout << "The square calculated result is : " << result << std::endl;
    calculateThread.join();
    return 0;
}
