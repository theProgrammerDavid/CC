# Recursion

- Structure of a recursive function

  ```c++
  int recursive_fn(struct node* node){
      // checks to end recursion 
      if(node==NULL)return 1;
  
      if(some condition)
          return 0;
      if(some_other_condition)
          return 1;
      
      if(!recursive_fn(node->left) || recursive_fn(node->right))
          return 0;
      
      return 1;
      
  }
  ```

  

- checking if a BST is valid or not

  ```c++
  int isBSTUtil(node* node, int min, int max);
  
  int isBST(node* node){
      return isBSTUtil(node, INT_MIN, INT_MAX);
  }
  
  
  int isBSTUtil(node* node, int min, int max){
      
    // an empty BST is valid
      if(node==nullptr)
          return 1;
      if(node->data < min || node->data > max)
          return 0;
      
      return isBSTUtil(node->left, min,node->data-1) && 
          isBSTUtil(node->right, node->data+1, max);
  }
  ```

  

- Find maximum combinations / total distinct ways 

  - A naughty kid is climbing a staircase of `n` steps. He can take either `1` step or `2` steps at a time. Write a program to find the number of distinct ways to reach the `nth` step.
    Assume he is standing on the `0th` step.

    Input format: 
    Single integer value that represents `n` steps

    Ans: 

    ```c++
    int waysToStep(int currStep, int n){
        if(currStep==n)return 1;
        if(currStep>n)return 0;
        
        return waysToStep(currStep+1, n) + waysToStep(currStep+2,n);
    }
    
    int main(){
        int n;
        cin>>n;
        cout<<waysToStep(0,n);
    }
    ```

    

- You have an `m` x `n` grid where you start at `(0,0)` and have to reach `(m-1,n-1)`and you can either move `right` or `down`. Find total number of ways to reach the destination. 

  Ans:

  ```c++
  int waysToMove(int currM, int currN, int M, int N){
      if(currM==n && currN==n)return 1;
      if(currM > n || currN > N)return 0;
      
      return waysToMove(currM+1, currN, M,N) + waysToMove(currM, currN+1, M, N);
  }
  
  int main(){
      int m,n;
      cin>>m>>n;
      cout<<waysToMove(0,0,M,N); 
  }
  ```

  

