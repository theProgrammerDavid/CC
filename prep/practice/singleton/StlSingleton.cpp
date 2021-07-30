#include <chrono>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill = 10'000'000;

class StlSingleton
{
public:
    static StlSingleton &getInstance()
    {
        std::call_once(initInstanceFlag, &StlSingleton::initSingleton);
        return *instance;
    }

private:
    StlSingleton() = default;
    ~StlSingleton() = default;
    StlSingleton(const StlSingleton &) = delete;
    StlSingleton &operator=(const StlSingleton &) = delete;

    static StlSingleton *instance;
    static std::once_flag initInstanceFlag;

    static void initSingleton()
    {
        instance = new StlSingleton;
    }
};

StlSingleton *StlSingleton::instance = nullptr;
std::once_flag StlSingleton::initInstanceFlag;

std::chrono::duration<double> getTime()
{
    auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i <= tenMill; i++)
    {
        StlSingleton::getInstance();
    }

    return std::chrono::system_clock::now() - begin;
}

int main()
{
    auto fut1 = std::async(std::launch::async, getTime);
    auto fut2 = std::async(std::launch::async, getTime);
    auto fut3 = std::async(std::launch::async, getTime);
    auto fut4 = std::async(std::launch::async, getTime);

    auto total = fut1.get() + fut2.get() + fut3.get() + fut4.get();
    std::cout << total.count() << std::endl;
}