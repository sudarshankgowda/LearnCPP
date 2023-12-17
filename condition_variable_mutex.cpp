#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool condition = false;

void waitingThread(){
    std::cout << "\nwaitingThread Function Entry" <<std::endl;
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return condition;});
    std::cout<<"\nCondition satisfied in waitingThread! Proceeding ..." << std::endl;
}

void notifyingThread(){
    std::cout << "\nnotifyingThread Function Entry" <<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(15));
    {
        //std::lock_guard<std::mutex> lock(mtx);
        condition = true;
    }
    cv.notify_one();
    std::cout << "\nnotifyingThread Function Exit" <<std::endl;
}

int main()
{
    std::cout << "Main Function Entry" <<std::endl;
    std::thread t1(waitingThread);
    std::thread t2(notifyingThread);
    t1.join();
    t2.join();
    std::cout << "Main Function Exit" <<std::endl;
    return 0;
}
