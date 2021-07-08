# C++ STL stuff

- rotate
  Included in `<algorithm>`

  ```c++
  std::rotate(ForwardIterator begin, ForwardIterator middle, ForwardIterator end);
  ```

  After rotation, element having iterator `middle` will be at the front and the elements before it will be added to the end. Rather, the container is shifted left and the elements that move out of the container are added to the end