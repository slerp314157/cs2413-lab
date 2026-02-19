// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen


bool isValid(const char* s) 
{
    // TODO: Implement using a stack.
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    // reject bad input
    if (s == NULL)
    {
        return false;
    }
    // reject if its odd in length.
    size_t len_text = strlen(s);
    if (len_text % 2 != 0)
    {
        return false;
    }
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    char stack[len_text];
    size_t top = 0;

    //   - If you see a closing bracket:
   //       * stack must not be empty
   //       * top of stack must match the closing bracket type
   //       * then pop
   // - At the end, stack must be empty.

    for (size_t i = 0; i < len_text; i++) 
    {
        char chr = s[i];


        // Opening bracket → push
        if (chr == '(' || chr == '[' || chr == '{') {
            stack[top++] = chr;
        }
        //   - If you see a closing bracket:
        else
        {
            //       * stack must not be empty
            if (top == 0)
            {
                return false;
            }
            //       * top of stack must match the closing bracket type

            char below = stack[--top];

            if ((chr == ')' && below != '(') || (chr == ']' && below != '[') || (chr == '}' && below != '{'))
            {
                return false;
            }
        }
    }

    return top == 0;
}
