### Threads



```c++
class X
{
public:
void do_lengthy_work();
};
X my_x;
std::thread t(&X::do_lengthy_work,&my_x);
```

- instances of std::thread are movable, even though they aren’t copyable
- ``std::thread::hardware_concurrency()`` . This function returns an indication of the number of threads that can
  truly run concurrently for a given execution of a program. On a multicore system it
  might be the number of CPU cores