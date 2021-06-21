# C++ Vector STL stuff

- ``std::vector`` stuff

  * sort a vector

    ```c++
    #include <functional.h> //for greater<int>( )
    #include <vector>
    #include <algorithm>
    
    std::vector<int> arr{1,12,-3,7,5};
    
    std::begin(arr.begin(), arr.end());
    std::begin(arr.begin(), arr.end(), greater<int>());
    
    ```

    * The **std::greater** is a functional object which is used  for performing comparisons. It is defined as a Function object class for the greater-than inequality comparison. 
      Alternatively, you can use `greater<int>( )` with C styled arrays too

      ```c++
      int arr[] = {1,12,-3,7,5};
      sort(arr, arr + 9, greater<int>());
      ```


  - slice a vector

    ```c++
    template <typename T>
    vector<T> slicing(vector<T> const& v,
                      int X, int Y)
    {
      
        // Begin and End iterator
        auto first = v.begin() + X;
        auto last = v.begin() + Y + 1;
      
        // Copy the element
        vector<T> vector(first, last);
      
        // Return the results
        return vector;
    }
    ```

    

- Remove duplicate elements 

  ```c++
  vec.resize(std::distance(vec.begin(), std::unique(vec.begin(), vec.end())));
  ```

  