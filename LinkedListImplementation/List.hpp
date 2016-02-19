//
//  List.h
//  LinkedList
//
//  Created by Aaron on 2/12/16.
//  Copyright © 2016 Aaron. All rights reserved.
//
// List.h

#ifndef LIST
#define LIST

#include <iostream>
#include <cstdlib>
#include <string>

typedef std::string ElementType;

class List
{
private:
    class Node
    {
    public:
        ElementType data;
        Node * next;
        
        Node( )
        : data( ElementType( ) ), next( NULL )
        { }
        
        Node( ElementType initData )
        : data( initData ), next( NULL )
        { }
    }; // end of Node class
    
    typedef Node * NodePointer;
   
    
public:
    List( );
    /* Construct a List object
     
     Precondition: none.
     Postcondition: An empty List object has been constructed.
     */
    
    List( const List &source );
    /* Construct a copy of a List object.
     
     Precondition: None.
     Postcondition: A copy of source has been constructed.
     */
    
    ~List( );
    /* Destroys a List object.
     
     Precondition:  None.
     Postcondition: All memory allocated to the List object has been freed.
     */
    
    const List & operator=( const List &rightSide );
    /* Assign a copy of a List object to the current object.
     
     Precondition: none
     Postcondition: A copy of rightside has been assigned to this
     object. A constant reference to this list is returned.
     */
    
    int getSize( ) const;
    /* Returns the size of the list (number of items in the list)
     
     Precondition: none
     Postcondition: The return value is the number of items in the list.
     */
    
    bool empty( ) const;
    /* Check if this List is empty
     
     Precondition: none
     Postcondition: The return value is true if this List object is empty;
     otherwise the return value is false.
     */
    
    void insert( ElementType dataVal, int index );
    /* Insert a value into this List at a given index
     
     Precondition:  The index is valid (0 <= index <= the list size).
     The first position is index 0, the second position is index 1, etc.
     Postcondition: dataval has been inserted into the list at the position
     determined by index (provided there is room and index is a legal
     position).
     */
    
    void erase( int index );
    /* Remove the value from this List at a given index.
     
     Precondition:  The list is not empty and index is valid
     (0 <= index < the list size).
     Postcondition: the element at position index has been
     removed (provided index is a legal position).
     */
    
    void display( std::ostream &out ) const;
    /* Display the contents of this List
     
     Precondition:  ostream out is open
     Postcondition: the items in this List have been output to stream out
     */
    
    
    int find( ElementType value) const;
    /* Find the first occurrence of a value in this List
     
     Preconditions:  None
     Postconditions: The return value is the index of the first List item
     that matches value. The first list item has index 0, the second has
     index 1, etc. The return value is -1 if value is not found in the list.
     */
   
    NodePointer getNthNode(int index);

private:
    NodePointer first;
    int mySize;
}; // end of List class

#endif /* List_h */
