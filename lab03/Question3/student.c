// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"


bool hasCycle(struct ListNode* head) 
{
    struct ListNode* slow_ptr = head;
    struct ListNode* fast_ptr = head;

    // checking for a cycle whilst not through every element in the list. 
    // while allows interation of address without allocating a "read only" head. 
    while (fast_ptr != NULL && fast_ptr->next != NULL) 
    {
        //move one address
        slow_ptr = slow_ptr->next;
        // moves two addresses forward
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            //if the two pointers meet, the fast cycled
            // and "raced up to" the slow pointer. thus there is a cycle. 
            return true;
        }
    }
    // or there was no cycle. 
    return false;
}