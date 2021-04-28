Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return *its sum*.

**Example 1:**

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Example 2:**

```
Input: nums = [1]
Output: 1
```

**Example 3:**

```
Input: nums = [5,4,-1,7,8]
Output: 23
```

- `O(N^2)` brute force approach 

  We iterate over each element of the array using `i`. For each element, the subsequent sub array from `i` to `nums.size()` will contain the answer. 

  ```c++
  int maxSubArray(vector<int>& nums) {
          int sum = INT_MIN;
          for(int i=0;i<nums.size();i++){
              int curr = 0;
              for(int j=i;j<nums.size();j++){
                  curr +=nums[j];
                  sum = max(sum, curr);
              }
          }
          
          return sum;
      }
  ```

  

- `O(N)` approach
  We know that the answer can be at least 1 element and can be at most `m` elements (where `m` is the size of the array). When we start the `for` loop, we know that we have to figure out some sort of a condition to compare 2 elements of the array with each other. 

  If the array is `arr` and we start from 0, we can say that, so far, the maximum subarray is `[arr[0]]`. But when we go to the next loop iteration, we can see that the maximum subarray can be either `[arr[0], arr[1]]` (eg. 2,4,-2, -1) or `[arr[1]]` (eg, -1, 2, -3).

  We can calculate the sum by comparing `nums[i]` and `curr + nums[i]` where `curr` is the sum of the subarray till now and the maximum of the two will be added to `curr`.

  But, `curr` might be overwritten in the next loop iteration, so we can keep another variable to store the global maximum sum and `curr` can store the local maximum sum. `curr`  's value will be assigned to the global maximum if `curr` > `global_max`.

  ```c++
  int maxSubArray(vector<int>& nums) {
          int sum = nums[0];
          int curr = sum;
          for(int i=1;i<nums.size();i++){
            curr = max(nums[i], curr+nums[i]);
              
              if(curr > sum)sum=curr;
          }
          
          return sum;
      }
  ```

  We don't want the `sum` or the global sum to be `INT_MIN` as the value may underflow when added with a `-ve` number. Hence we start the loop from 1 and have sum = `arr[0]`