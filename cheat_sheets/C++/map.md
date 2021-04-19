# C++ STL Map Stuff

[begin()](https://www.geeksforgeeks.org/mapbegin-end-c-stl/) – Returns an iterator to the first element in the map

[end()](https://www.geeksforgeeks.org/mapbegin-end-c-stl/) – Returns an iterator to the theoretical element that follows last element in the map

[size()](https://www.geeksforgeeks.org/mapsize-c-stl/) – Returns the number of elements in the map

[max_size()](https://www.geeksforgeeks.org/map-max_size-in-c-stl/) – Returns the maximum number of elements that the map can hold

[empty()](https://www.geeksforgeeks.org/mapempty-c-stl/) – Returns whether the map is empty

[pair insert(keyvalue, mapvalue)](https://www.geeksforgeeks.org/map-insert-in-c-stl/) – Adds a new element to the map

[erase(iterator position)](https://www.geeksforgeeks.org/map-erase-function-in-c-stl/) – Removes the element at the position pointed by the iterator

[erase(const g)](https://www.geeksforgeeks.org/map-erase-function-in-c-stl/)– Removes the key value ‘g’ from the map

[clear()](https://www.geeksforgeeks.org/mapclear-c-stl/) – Removes all the elements from the map

```c++
std::map<int, int> m;

m.insert(pair<int, int>(1,2));
m.insert(pair<int, int>(3,5));

//remove all elements upto element with key=3
m.erase(m.begin(), m.find(3));

//remove all elements with key=4;
m.erase(4);

//iterate through map
std::map<int, int>::iterator it;
for(it = m.begin();i!=m.end(); ++itr){
    std::cout<< it->first << it->second << '\n';
}
```
> `std::map<int,int>::iterator` it can be replaced with `auto`
