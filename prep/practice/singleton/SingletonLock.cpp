// singletonLock.cpp

#include <chrono>
#include <iostream>
#include <future>
#include <mutex>

constexpr auto tenMill = 10'000'000;
std::mutex m;
class SingletonLock
{
public:
    static SingletonLock &getInstance()
    {
        std::lock_guard<std::mutex> lock(m);
        if (!instance)
        {
            instance = new SingletonLock();
        }
        return *instance;
    }

private:
    SingletonLock() = default;
    ~SingletonLock() = default;
    SingletonLock(const SingletonLock &) = delete;
    SingletonLock &operator=(const SingletonLock &) = delete;
    static SingletonLock *instance;
};

SingletonLock *SingletonLock::instance = nullptr;

std::chrono::duration<double> getTime()
{

    auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i <= tenMill; ++i)
    {
        SingletonLock::getInstance();
    }
    return std::chrono::system_clock::now() - begin;
};

int main()
{

    auto fut1 = std::async(std::launch::async, getTime);
    auto fut2 = std::async(std::launch::async, getTime);
    auto fut3 = std::async(std::launch::async, getTime);
    auto fut4 = std::async(std::launch::async, getTime);

    auto total = fut1.get() + fut2.get() + fut3.get() + fut4.get();

    std::cout << total.count() << std::endl;
}