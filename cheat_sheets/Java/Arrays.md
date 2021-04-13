# Arrays and Stuff

- Array slice 

  ```java
  import java.util.Arrays.copyOfRange;
  
  // function definition
  // first parameter is a template, can be any type of array
  public static int[] copyOfRange(int[] originalArray, int fromIndex, int toIndex);
  
      .
      .
      .
  	int arr[] = { 12, 13, 14, 15, 16, 17, 18 };
  	int copy[] = Arrays.copyOfRange(arr, 2,6);
  	int copy1[] = Arrays.copyOfRange(arr, 4, arr.length+3);
  ```

  1.  The initial index i.e(`from_index`) must lie within 0 to `original_array.length`

  2. The final index i.e(``to_index``) can be greater than or equal to length of  original array. 
  3. In case it is greater than the original Array then 0’s  is assigned to the copy whose index is greater than or equal to  `original.length – from`.
  4. Return array has length of will be `to-from`