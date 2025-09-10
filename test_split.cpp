/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <cstddef>
#include <iostream>
#include "split.h"

int main(int argc, char* argv[])
{
  // Node node5(5, NULL);
  // Node node4(4, &node5);
  // Node node3(3, &node4);
  // Node node2(2, &node3);
  // Node node1(1, &node2);
  // Node node0(0, &node1);
  // Node* head = &node0;
  Node* head = nullptr;

  Node* evens = nullptr;
  Node* odds = nullptr;

  split(head, evens, odds);
  

  while(evens != nullptr){
    std::cout << "Evens: " << evens->value << '\n';
    evens = evens->next;
  }

  while(odds != nullptr){
    std::cout << "Odds: " << odds->value << '\n';
    odds = odds->next;
  }
  return 0;
}
