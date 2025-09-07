/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char *argv[])
{
    Node *linkedListIn = new Node(0, nullptr);
    for(int i = 0; i < 25; i++)
    {
        Node *newNode = new Node(i, nullptr);
    }

    return 0;
}
