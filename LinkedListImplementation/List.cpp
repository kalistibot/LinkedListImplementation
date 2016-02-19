//
//  List.cpp
//  LinkedList
//
//  Created by Aaron on 2/12/16.
//  Copyright © 2016 Aaron. All rights reserved.
//

#include <stdio.h>
#include "List.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

typedef std::string ElementType;
/* Construct a List object
 
 Precondition: none.
 Postcondition: An empty List object has been constructed.
 */
List::List( )
:first(0),mySize(0)
{}

/* Construct a copy of a List object.
  Precondition: None.
 Postcondition: A copy of source has been constructed.
 */
List:: List( const List &source ){
    mySize = source.mySize;
    first = 0;
    if (!source.empty()){
        first = new Node(source.first->data);
        NodePointer lastPtr = first,
                    origPtr = source.first->next;
        while (origPtr !=0) {
            lastPtr->next = new Node(origPtr->data);
            lastPtr = lastPtr->next;
            origPtr = origPtr->next;
        }
    
    }
    
}


/* Destroys a List object.
 
 Precondition:  None.
 Postcondition: All memory allocated to the List object has been freed.
 */
List:: ~List( ){
    
    NodePointer currPtr = first,
                nextPtr;
  
    while (currPtr !=0){
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
    first = NULL;
}

/* Assign a copy of a List object to the current object.
 
 Precondition: none
 Postcondition: A copy of rightside has been assigned to this
 object. A constant reference to this list is returned.
 */

const List & List::operator=( const List &rightSide ){

    if (this != &rightSide){
        this->~List();
        if (rightSide.empty())
            first = 0;
        else{
            first = new Node(rightSide.first->data);
            NodePointer lastPtr = first,
                        rhsPtr  = rightSide.first->next;
        
            while (rhsPtr !=0) {
                lastPtr->next = new Node(rhsPtr->data);
                lastPtr = lastPtr->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    this->mySize = rightSide.mySize;
    return *this;
 }


/* Returns the size of the list (number of items in the list)
 
 Precondition: none
 Postcondition: The return value is the number of items in the list.
 */

int List::getSize( ) const{
    return mySize;
}

/* Check if this List is empty
 
 Precondition: none
 Postcondition: The return value is true if this List object is empty;
 otherwise the return value is false.
 */
bool List::empty( ) const{
    return (mySize == 0);
}


/* Insert a value into this List at a given index
 
 Precondition:  The index is valid (0 <= index <= the list size).
 The first position is index 0, the second position is index 1, etc.
 Postcondition: dataval has been inserted into the list at the position
 determined by index (provided there is room and index is a legal
 position).
 */

void List::insert( ElementType dataVal, int index ){
    if (index < 0|| index > mySize) {
        std::cerr<<"Index out of range. Nothing inserted"<<std::endl;
        return;
    }

    if (empty()){
        NodePointer ptr = new Node(dataVal);
        ptr->next = first;
        first = ptr;
    }else{
        NodePointer newptr = new Node(dataVal);
        NodePointer predptr = getNthNode(index - 1);
        newptr->next = predptr->next;
        //reassign the previous pointer unless the new node is going in the front
        if (index >0)
            predptr->next = newptr;
        if (index == 0){
            first = newptr;
            newptr->next = predptr;
            if (mySize==1)
                predptr->next = 0;
        }
    }
    mySize++;
}
/* Remove the value from this List at a given index.
 
 Precondition:  The list is not empty and index is valid
 (0 <= index < the list size).
 Postcondition: the element at position index has been
 removed (provided index is a legal position).
 */
void List::erase( int index ){
    
    if (index < 0|| index > mySize) {
        std::cerr<<"Index out of range. Nothing deleted"<<std::endl;
        return;
    }
    if ( mySize== 0) {
        std::cerr<<"List is Empty. Nothing to delete"<<std::endl;
        return;
    }
    
    NodePointer eraseptr = getNthNode(index);
    if (index ==0) {
        first = first->next;
        delete eraseptr;
        
    }else{
        NodePointer predptr = getNthNode(index -1);
        predptr->next =eraseptr->next;
        delete eraseptr;
    }
    mySize--;
}


/* Display the contents of this List
 
 Precondition:  ostream out is open
 Postcondition: the items in this List have been output to stream out
 */

void List::display( std::ostream &out ) const{
    NodePointer ptr = first;
    while (ptr !=0) {
        out << ptr->data<<' ';
        ptr =  ptr->next;
        
    }
}
/* Find the first occurrence of a value in this List
 
 Preconditions:  None
 Postconditions: The return value is the index of the first List item
 that matches value. The first list item has index 0, the second has
 index 1, etc. The return value is -1 if value is not found in the list.
 */
int List::find( ElementType value) const{
    
    int count = 0;
    NodePointer ptr = first;
    while (ptr !=NULL) {
        if (ptr->data == value)
            return count;
        count++;
        ptr = ptr->next;
    }
    return  -1; //not found
}


/*
 Preconditions: None
 Postcondition:  The return value is a pointer to the node at a given index in the list
 */
List::NodePointer List::getNthNode(int index){
    if (index < 0|| index > mySize) {
        std::cerr<<"Index out of range. Null ptr returned"<<std::endl;
        List::NodePointer barfPtr = new Node("barf");
        return barfPtr;
    }
    NodePointer ptr = first;
    int count = 0;
    if (index < 0) // if the position is 0
        index = 0;
    while (ptr!= NULL){
        if (count == index)
            return ptr;
        ptr =ptr->next;
        count++;
    }
    assert(0);
}


