### Binary Search Tree

- Search for Node/value (recursive)

  - Algorithm
    if `current node` is `NULL`, return `root` (which is NULL)
    if `(current node).val == val` then we return `root`

    We start with the left sub tree first and then go to the right

  ```c++
  TreeNode* searchBST(TreeNode* root, int val){
      if(root==NULL || val == root->val)return root;
      
      if(val< root->val)return searchBST(root->left, val);
      else return searchBST(root->right, val);
  }
  
  ```

- Search for Node/value (iterative)

  - Algorithm
    Same as the recursive approach except that we have to move a pointer through the tree in the same way as a recursive approach, but with a loop. 
    We use a `while` loop with the same termination conditions as the recursive approach, but the loop has to run when both are true.
    We use the pointer `root` to traverse through the tree

  ```c++
  TreeNode* searchBST(TreeNode* root, int val){
      while(root != NULL && val != root->val){
          root = val < root->val ? root->left : root->right;
      }
      
      return root;
  }
  ```

  