# Set, HashSet and TreeSet 

- Set - generic set of values with no duplicate elements

- TreeSet - set where elements are sorted

- HashSet - set where elements are not sorted. Faster than TreeSet, and is an implementation of a Set

  ###### Example:

  ```java
  import java.util.*;
  .
  .
  .
      int a[] = {5,2,12,34,42,9,0,-4};
   	Set<Integer> s = new HashSet<Integer>();
  	
  	for(int i:a){
          s.add(i);
      }
  	
  	TreeSet ts = new TreeSet<Integer>(s);
  	System.out.println(ts);
  ```

  

###### Find Maximum in a set

```java
Set<Integer> s = new HasHSet<>();
.
.
int maximum = Collections.max(s);
```

###### Remove Element from Set

```java
Set<Integer> s = new HashSet<>();
int maximum = Collections.max(s);
s.remove(maximum);
```

###### Other functions 

```java
Set<Integer> s = new HashSet<>();
int size = s.size();
boolean b = s.contains(50);
```

