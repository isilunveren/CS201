//Isil Unveren
//Section 1
//22202444
//
//
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <string>
#include <iostream>

class Queue {
private:
    Node* front;
    Node* back;

public:
    Queue(){
        front = nullptr;
        back = nullptr;
    }
    
    ~Queue(){
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const{
        return front == nullptr;
    }
    
    void enqueue(int row, int col){
        
        Node* newNode = new Node(row, col);
        if (back) {
            back->next = newNode;
        }
        else {
            front = newNode;
        }
        back = newNode;
    }
    
    void dequeue(){
        if (isEmpty()){
            return;
        }
        Node* temp = front;
        front = front->next;
        if (!front) {
            back = nullptr;
        }
        delete temp;
    }
    
    Node* peek() const{
        return front;
    }
};
#endif
