#include <chrono>
#include <iostream>
#include <future>
using namespace std;

class MySingleton
{
public:
    static MySingleton &getInstance()
    {
        static MySingleton instance;
        return instance;
    }

private:
    MySingleton() = default;
    ~MySingleton() = default;
    MySingleton(const MySingleton &) = delete;
    MySingleton &operator=(const MySingleton &) = delete;
};

constexpr auto tenMillion = 10'000'000;

std::chrono::duration<double> getTime()
{

    auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i <= tenMillion; ++i)
    {
        MySingleton::getInstance();
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