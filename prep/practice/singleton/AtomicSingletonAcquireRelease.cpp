#include <atomic>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill = 10'000'000;

class AtomicSingleton
{
public:
    static AtomicSingleton *getInstance()
    {
        AtomicSingleton *tempInstance = instance.load(std::memory_order_acquire);

        if (!tempInstance)
        {
            //we have to initialize the variable
            std::lock_guard<std::mutex> lock(m);
            tempInstance = instance.load(std::memory_order_relaxed);

            if (!tempInstance)
            {
                tempInstance = new AtomicSingleton();
                instance.store(tempInstance, std::memory_order_release);
            }
        }

        return tempInstance;
    }

private:
    AtomicSingleton() = default;
    ~AtomicSingleton() = default;
    AtomicSingleton(const AtomicSingleton &) = delete;
    AtomicSingleton &operator=(const AtomicSingleton &) = delete;

    static std::atomic<AtomicSingleton *> instance;
    static std::mutex m;
};

std::atomic<AtomicSingleton *> AtomicSingleton::instance;
std::mutex AtomicSingleton::m;

std::chrono::duration<double> getTime()
{

    auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i <= tenMill; ++i)
    {
        AtomicSingleton::getInstance();
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