- - - # Linked Lists

      
      
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

          

- Check if Linked List has loop
  Two pointers - p1 and p2. p2 has 2x speed of p1
  If ``p1==p2`` (compare using memory address and not data part of node) then we found a cycle

  ```c++
  bool hasCycle(ListNode *head) {
          if(head==NULL)
              return false;
          if(head->next==NULL)
              return false;
          
          ListNode *p1 = head, *p2 = head->next;
          
          while(p1 != p2 ){
              if(p2==NULL || p2->next == NULL){
                  return false;
              }
              
              p1 = p1->next;
              p2 = p2->next;
              p2 = p2->next;
          }
          
          return true;
      }
  ```

- Return Node where cycle begins
  HashMap

  ```c++
  ListNode *detectCycle(ListNode *head) {
             	std::set<ListNode*> visited;
          	ListNode *temp = head;
          
          while(temp!=NULL){
              const bool isIn = visited.find(temp) != visited.end();
              if(isIn){
                  return temp;
              }
              
              visited.insert(temp);
              temp = temp->next;
          }
          
          return NULL;
      }
  ```

  2 pointer
  	Step 1: find where cycle begins (Intersection)

  ​	Step 2: start incrementing the `slow`, `fast` and `entry` pointers.  `slow` and `fast` will loop in the cycle 
  ​			`L1` is defined as the distance between the head point and entry point
  ​			`L2` is defined as the distance between the entry point and the meeting point
  ​			`C`   is defined as the length of the cycle
  ​			`n` is defined as the no. of loops `fast` makes when `fast` first meets `slow`
  
  ​			Distance traveled by slow when they meet: L1+L2
  ​			Distance traveled by fast when they meet: L1+L2+x+L2, where x is the  remaining length of the cycle (meeting point to start of the cycle).
  
  ```
  2(L1+L2) = L1+L2+x+L2
   2L1 + 2L2 = L1+2L2+x
   => x = L1
  ```
  
  
  
  ```c++
ListNode *detectCycle(ListNode *head) {
      if (head == NULL || head->next == NULL)
          return NULL;
      
      ListNode *slow  = head;
      ListNode *fast  = head;
      ListNode *entry = head;
      
      while (fast->next && fast->next->next) {
          slow = slow->next;
          fast = fast->next->next;
          if (slow == fast) {                      // there is a cycle
              while(slow != entry) {               // found the entry location
                  slow  = slow->next;
                  entry = entry->next;
              }
              return entry;
          }
      }
      return NULL;                                 // there has no cycle
  }
  ```
  
  ​	Step 2: traverse the cycle and 