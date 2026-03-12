/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isAVL(struct TreeNode* root)
{
    int result = chk_balancing(root, LONG_MIN, LONG_MAX);

    if (result == -1) 
    {
        return false;
    }

    return true;
}


int chk_balancing(struct TreeNode* node, long min, long max)
{
    //invalid node. 
    if (node == NULL) 
    {
        return 0;
    }

    // not properly structured
    if (node->val <= min || node->val >= max) 
    {
        return -1;
    }

    // get the height of the left subtree and right subtrees.
    int rightHeight = chk_balancing(node->right, node->val, max);
    int leftHeight = chk_balancing(node->left, min, node->val);
    int diff = leftHeight - rightHeight;


    if (leftHeight == -1) 
    {
        return -1;
    }

    if (rightHeight == -1) 
    {
        return -1;
    }

    // not balanced. 
    if (diff < -1 || diff > 1) 
    {
        return -1;
    }

       
    if (leftHeight > rightHeight) 
    {
        return leftHeight + 1;
    }
    else 
    {
        return rightHeight + 1;
    }
}


