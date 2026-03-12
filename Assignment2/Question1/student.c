/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 *   struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run1
 */

#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) 
{
    while (root != NULL) 
    {
        // found the root of the tree to be equal
        if (target == root->val) 
        {
            return root;
        }
        // otherwise the sorting pattern must be used, and we move the root downwards, to the subtree. 
        else if (target < root->val) 
        {
            root = root->left;
        }
        else 
        {
            root = root->right;
        }
    }
    return NULL;
}