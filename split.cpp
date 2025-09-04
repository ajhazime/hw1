/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node *&in, Node *&odds, Node *&evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE

  // Base Case Node_in is empty
  if (!in)
  {
    evens = nullptr;
    odds = nullptr;
    return;
  }

  Node *nextNode = in->next;
  in->next = nullptr;

  Node *evenNode = nullptr;
  Node *oddNode = nullptr;
  split(in, odds, evens);

  if(isEven(in->value)){
    in->next = evenNode;
    evens = in;
    odds = oddNode;
  } else {
    in->next = oddNode;
    odds = in;
    evens = evenNode;
  }
}

/* If you needed a helper function, write it here */

// Helper function to determine even/odd numbers
bool isEven(int n)
{
  if (n % 2 == 0 || n == 0)
  {
    return true;
  }
  return false;
}
