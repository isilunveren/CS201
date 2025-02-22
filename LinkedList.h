// Isil Unveren
// Section 1
// 22202444

#ifndef LinkedList_h
#define LinkedList_h
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <cstddef>

template <class ItemType>
class LinkedList {
private:
    
    //private data members
    Node<ItemType>* headPtr;
    int itemCount;
public:
    
    //default constructor
    LinkedList(){
        headPtr = nullptr;
        itemCount = 0;
    }
    
    //copy constructor
    LinkedList(const LinkedList<ItemType>& aList){
        headPtr = aList.headPtr;
        itemCount = aList.itemCount;
    }
    
    //method to remove all items in the linked list
    void clear(){
        while (headPtr != nullptr){
            Node<ItemType>* temp = headPtr;
            headPtr = headPtr -> getNext();
            delete temp;
        }
        itemCount = 0;
    }
    
    //destructor
    ~LinkedList(){
        clear();
    }
    
    bool isEmpty() const{
        return itemCount == 0;
    }
    
    int getLength() const{
        return itemCount;
    }
    
    Node<ItemType>* getHeadPtr() const{
        return  headPtr;
    }
    
    bool doesExist(ItemType& item){
        Node<ItemType>* cur = headPtr;
        for (int i = 0; i < itemCount && cur != nullptr; i++){
            if(cur -> getItem() == item){
                return true;
            }
            cur = cur -> getNext();
            
        }
        return false;
    }
    
    //to create an unsorted linked list
    bool insertUnsorted(ItemType& newItem){
        if (doesExist(newItem)){
            return false;
        }
        Node<ItemType>* newNode = new Node<ItemType>(newItem);
            if (headPtr == nullptr) {
                headPtr = newNode;
            }
            else {
                Node<ItemType>* cur = headPtr;
                Node<ItemType>* prev = nullptr;
                while (cur != nullptr) {
                    prev = cur;
                    cur = cur->getNext();
                }
                newNode->setNext(nullptr);
                prev->setNext(newNode);
                
            }
        itemCount++;
        return true;
    }
    
    //to create a sorted linked list
    bool insertSorted(ItemType& newItem){

        if (doesExist(newItem)){
            return false;
        }
        Node<ItemType>* newNode = new Node<ItemType>(newItem);
            if (headPtr == nullptr) {
                headPtr = newNode;
            }
            else {
                Node<ItemType>* cur = headPtr;
                Node<ItemType>* prev = nullptr;
                while (cur != nullptr && cur->getItem() < newItem) {
                    prev = cur;
                    cur = cur->getNext();
                }
                if (prev == nullptr) {
                    newNode->setNext(headPtr);
                    headPtr = newNode;
                } else {
                    newNode->setNext(cur);
                    prev->setNext(newNode);
                }
                
            }
        itemCount++;
        return true;
    }
    
    
    bool remove(ItemType& itemToRemove){
        if (doesExist(itemToRemove)){
            Node<ItemType>* cur = headPtr;
            Node<ItemType>* prev = nullptr;
            while (cur != nullptr){
                if (cur->getItem() == itemToRemove){
                    if (prev == nullptr){
                        headPtr = cur -> getNext();
                    }
                    else{
                        prev->setNext(cur->getNext());
                    }
                    cur->setNext(nullptr);
                    delete cur;
                    cur = nullptr;
                    itemCount--;
                    return true;
                }
                prev = cur;
                cur = cur->getNext();
            }

        }
        return false;
       
        
    }

    Node<ItemType>* getNodeAt (int position) const{
        if(position == 1 && itemCount == 0){
            return nullptr;
        }
        if (position >= 1 && position <= itemCount){
            Node<ItemType>* cur = headPtr;
            for (int i = 1; i < position; i++){
                cur = cur -> getNext();
            }
            return cur;
        }
        else {
            return nullptr;
        }
    }
    

    
};
#endif /*LinkedList_h*/

