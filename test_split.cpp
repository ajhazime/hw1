/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <cstddef>
#include "split.h"

int main(int argc, char* argv[])
{
  Node node5(5, NULL);
  Node node4(4, &node5);
  Node node3(3, &node4);
  Node node2(2, &node3);
  Node node1(1, &node2);
  Node Node0(0, &node1);
  Node* head = &Node0;

  Node* evens = nullptr;
  Node* odds = nullptr;

  split(head, evens, odds);
  std::cout << heads->value << '\n' << odds->value << std::endl;
  return 0;
}
