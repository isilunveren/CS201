//Isil Unveren
//Section 1
//22202444
//
//
#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>

class Node {
public:
    int row, col;
    Node* next;

    Node(int rowGiven, int colGiven){
        row = rowGiven;
        col = colGiven;
        next = nullptr;
    }
};
#endif
