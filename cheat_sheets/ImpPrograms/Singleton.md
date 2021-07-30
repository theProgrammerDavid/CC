### Singleton
> Complete Article [here](https://www.modernescpp.com/index.php/thread-safe-initialization-of-a-singleton)
- Meyers Singleton
```c++
class MySingleton{
public:
  static MySingleton& getInstance(){
    static MySingleton instance;
    return instance;
  }
private:
  MySingleton()= default;
  ~MySingleton()= default;
  MySingleton(const MySingleton&)= delete;
  MySingleton& operator=(const MySingleton&)= delete;

};
```

- Singleton using C++ Atomics
```c++
class AtomicSingleton
{
public:
    static AtomicSingleton *getInstance()
    {
        AtomicSingleton *tempInstance = instance.load();

        if (!tempInstance)
        {
            //we have to initialize the variable
            std::lock_guard<std::mutex> lock(m);
            tempInstance = instance.load();

            if (!tempInstance)
            {
                tempInstance = new AtomicSingleton();
                instance.store(tempInstance);
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

```

- C++ Atomic Singleton (but faster)

```c++
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
```