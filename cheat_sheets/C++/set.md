# C++ SET STL stuff

- check if set has element 

  ```c++
  std::set<int> s;
  
  const bool is_in = s.find(element) != s.end();
  
  //c++ 20
  const bool is_in = s.contains(element);

  //insert  
  s.insert(4);

  ```
  
  