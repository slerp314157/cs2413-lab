// Question1/student.c
// ------------------------------------------------------------
// CS Lab03 - Reverse Linked List 
//
// TODO:
//   Implement reverseList(head) to reverse a singly linked list.
//
// Rules:
// - Do not allocate new nodes.
// - Do not use recursion.
// - Return the new head pointer.
// ------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "student.h"

struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode* prev_node = NULL;
    struct ListNode* curr_node = head;
    struct ListNode* next_node = NULL;

    while (curr_node != NULL) 
    {
        next_node = curr_node->next;
        // reverse the nodes. 
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    return prev_node;
}