// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"


struct ListNode* swapPairs(struct ListNode* head) 
{
    // filtering bad input. 
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode* swapped_head = head->next;
    struct ListNode* prev_ptr = NULL;
    struct ListNode* curr_ptr = head;

    while (curr_ptr != NULL && curr_ptr->next != NULL) 
    {
        struct ListNode* next = curr_ptr->next;
        struct ListNode* nextPair = next->next;

        // swap
        next->next = curr_ptr;
        curr_ptr->next = nextPair;

        //connect the previous pair
        if (prev_ptr != NULL) 
        {
            prev_ptr->next = next;
        }

        prev_ptr = curr_ptr;
        curr_ptr = nextPair;
    }

    return swapped_head;
}