### Linked List

- Remove Duplicate Elements 
```c++
//https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
/* C++ Program to remove duplicates in an unsorted
linked list */
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void removeDuplicatesNoSpace(struct Node *head)
{
    struct Node *ptr1, *ptr2, *temp;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                temp = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete temp;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }

        ptr1 = ptr1->next;  
    }
}

void removeDuplicates(struct Node *start)
{
    std::unordered_map<int, bool> m;
    struct Node *ptr = NULL;

    while (start != NULL)
    {
        if (m.find(start->data) != m.end())
        {
            ptr->next = start->next;
        }
        else
        {
            m.insert({start->data, true});
            ptr = start;
        }
        start = start->next;
    }
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above function */
int main()
{
    /* The constructed linked list is:
	10->12->11->11->12->11->10*/
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next = newNode(11);
    start->next->next->next->next->next->next = newNode(10);
    start->next->next->next->next->next->next->next = newNode(15);
    start->next->next->next->next->next->next->next->next = newNode(15);

    printf("Linked list before removing duplicates ");
    printList(start);

    removeDuplicatesNoSpace(start);

    printf("\nLinked list after removing duplicates ");
    printList(start);

    return 0;
}


```