
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::mutex m1;
std::mutex m2;

long long bankBalance=0;


void thread1() {
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m2.lock();
    cout << "Critical Section of Thread Thread One" << endl;
    m1.unlock();
    m2.unlock();
}
void thread2() {
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m2.lock();
    cout << "Critical Section of Thread Thread Two" << endl;
    m2.unlock();
    m1.unlock();
}

std::mutex m;

void addMoney(long long val)
{
    m.lock();
    bankBalance += val;
    m.unlock();
}

int main()
{

    //thread t1(thread1);
    //thread t2(thread2);
    //t1.join();
    //t2.join();

    std::thread t1(addMoney, 100);
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    std::thread t2(addMoney, 200);

    t1.join();
    t2.join();

    cout << "Final BankBalance : " << bankBalance << endl;

    return 0;
  }