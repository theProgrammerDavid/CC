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

  