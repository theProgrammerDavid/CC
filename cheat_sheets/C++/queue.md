### Queues

```c++
#include <queue>

std::queue<int> q;

q.push(10);
q.push(20);
q.push(5);

q.top(); //10
q.pop();

```



- Priority Queue (alternate definition)

  ```c++
  std::priority_queue<int, vector<int>, greater<int>> q;
  std::priority_queue<int, vector<int>, less<int>> q;
  ```

  