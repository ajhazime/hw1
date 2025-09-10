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

bool isEven(int n);

void split(Node *&in, Node *&odds, Node *&evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE

  /* Base Case Node_in is empty */
  if (!in){
    return;
  } 
  
  Node* currentNode = in; //current node 
  in = in->next; //moving in node by 1 to the right
  currentNode->next = nullptr; //detaching current node->next to nullptr

  if (isEven(currentNode->value)) { // if the value is even
    evens = currentNode; //set evens to current node
    return split(in, odds, evens->next); //pass updated in, and nullptr odds/evens
  } else {
    odds = currentNode;
    return split(in, odds->next, evens);//pass updated in, and nullptr odds/evens
  }
}

/* If you needed a helper function, write it here */

/* Helper function to determine even/odd numbers */
bool isEven(int n)
{
  if (n % 2 == 0 || n == 0)
  {
    return true;
  }
  return false;
}
