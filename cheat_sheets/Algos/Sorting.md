# Sorting 

- Merge Sort (top down approach)

  ```java
  import java.util.Arrays;
  public class Solution{
      public int[] merge_sort(int []input){
          
          if(input.length <=1){
              reutrn input;
          }
          
          int pivot = input.length/2;
          
          int[] leftArray = merge_sort(Arrays.copyOfRange(input, 0, pivot));
          int[] rightArray = merge_sort(Arrays.copyOfRange(input,pivot, 													input.length));
          
          return merge(leftArray, rightArray);
      	}
      
      public int[] merge(int []leftArray, int []rightArray){
          int []returnArray = new int[leftArray.length + rightArray.length];
          
          int leftCursor=0, rightCursor=0, returnCursor=0;
          
          while(leftCursor < leftArray.length 
                && rightCursor < rightCursor.length){
              
              if(leftArray[leftCursor] < rightArray[rightCursor]){
                  returnArray[returnCursor++] = leftArray[leftCursor++];
              }
              else{
                  returnArray[returnCursor++] = rightArray[rightCursor++];
              }
          }
          
          while(leftCursor < leftArray.length)
              returnArray[returnCursor++] = leftArray[leftCursor++];
          while(rightCursor < rightArray.length)
              returnArray[returnCursor++] = rightArray[rightCursor++];   
      
  	return returnArray;
  }
  }
  ```




