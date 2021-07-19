### Heaps

- Given an `n x n` matrix in ascending order, find the `kth` smallest element in the matrix
  [Leetcode Question](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

  ```python
  import heapq
  
  class Solution:
  	def kthSmallest(self, matrix: List[List[int]], k:int) -> int:
          N = len(matrix)
          ans = []
          # ans will be our heap
          
          for r in range(min(k,N)):
              ans.append((matrix[r][0], r, 0))
              # we store extra info in the matrix. matrix[r][0] is an element of the rth list, r is the index of the list and 0 is the nth element of the rth list
          heapq.heapify(ans) #makes the list a heap
          
          while k:
              #since we have to find the kth element, we iterate over the heap list k times
              elmeent, r, c = heapq.heappop(ans)
              
              # condition to check if the rth list has any remaining elements. If c (the element pointer) is less than N-1 (size of a list bcoz nxn array), we add the c+1th element to the heap
              if c < N -1:
                  heapq.heappush(ans, (matrix[r][c+1], r, c+1))
              k-=1
         	return element
      #element is the kth smallest element after the iterations are over
  ```

  

