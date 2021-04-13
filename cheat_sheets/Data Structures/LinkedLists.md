# Linked Lists



```c++
struct Node{
    int val;
    Node *next;
    Node(int x): val(x), next(NULL){}
}
```

```java
public class Node{
    int val;
    Node next;
    Node(int x)
    {
        val=x;
    }
}
```

- Information
  - ``O(n)`` for traversal

- get `ith` element from head

  ```c++
  ListNode* getNode(int index){
      ListNode *temp = head;
      for(int i=0;i<index;i++){
          temp = temp->next;
      }
      return temp;
  }
  ```

  - print linked list in reverse

    ```c++
    void printLinkedListInReverse(ImmutableListNode* head) {
           if(head !=nullptr){
                printLinkedListInReverse(head->getNext());
               cout<<head->val<<' ';
               return ;
           }
            
    ```

    - reverse a linked list

      ```c++
      void ReverseList(ImmutableListNode* head) {
             if(head==nullptr)return;
              
              ImmutableListNode *prev =NULL, *curr = head, *temp=NULL;
              
              while(curr!=NULL){
                  
                  temp = curr->next;
                  
                  //reverse the link
                  curr->next = prev;
                  
                  prev = curr;
                  curr = temp;
              }
              
              head=prev;
          }
      ```

      