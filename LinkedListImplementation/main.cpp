//
//  main.cpp
//  LinkedList
//
//  Created by Aaron on 2/12/16.
//  Copyright © 2016 Aaron. All rights reserved.
//

#include <iostream>
#include "List.hpp"
#include <cmath>
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
using namespace::std;


void print_menu( );
void displayCopiedList(List original);
void displayAssignment(List original);

int main( )
{
    List test;     // A List to perform tests on
    ElementType dataPart;
    char choice;   // Command entered by the user
    
    cout << "I have initialized an empty Linked List." << endl;
    
    do
    {
        print_menu( );
        cout << "Enter choice: ";
        cin >> choice;
        choice = toupper(choice);
        string search;
        int searchResult;
        int index = 0;
        switch (choice)
        {
            case 'S':
                cout<< test.getSize();
                break;
            case 'N':
                cout<<"\n Which position to test?";
                cin>> index ;
                cout<< "result: "<< test.getNthNode(index)->data<<endl;
                break;
            case 'E':
                if (test.empty())
                    cout <<"The list is empty..."<<endl;
                else
                    cout <<"The list is not empty..."<<endl;
                break;
            case 'P':
                cout<<"\nPrinting List: ";
                test.display(cout);
                break;
            case 'I':
                cout<< "\nWhich position to insert?";
                cin>>index;
                cout << "Type a string to insert: "<< endl;
                cin >> dataPart;
                cout<< "\nInserting "<< dataPart <<" at "<< index <<endl;
                test.insert(dataPart, index);
                break;
            case 'C':
                cout << "Original list: ";test.display(cout);
                cout << "Copied list: ";displayCopiedList(test);
                break;
            case 'D':
                cout<< "\nWhich position to erase?";
                cin>>index;
                if (test.getNthNode(index)->data != "barf"){
                    cout<<"Deleting "<< test.getNthNode(index)->data <<endl;
                    test.erase(index);
                }else{
                    cout<<" Nothing deleted..."<<endl;
                }
                break;
            case 'F':
                cout<<"\n Enter search term: ";
                cin>> search;
                searchResult = test.find(search);
                if (searchResult == -1){
                    cout<< search  <<" Not Found.";
                }else{
                    cout<<"Match found at position "<<searchResult<<endl;
                }
                break;
            case 'A':
                cout<<"Newly assigned list:";displayAssignment(test);
                break;
            case 'Q': cout << "Test program ended." << endl;
                break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
    
    return EXIT_SUCCESS;
}

void print_menu( )
{
    
    cout << "\nThe following choices are available: " << endl;
    cout << " S   Print the size of the list" << endl;
    cout << " N   Print the result of getNthNode" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print a copy of the entire list" << endl;
    cout << " I   Insert a new string with the insert(...) function" << endl;
    cout << " C   Make a copy of the list and print the copy" << endl;
    cout << " D   Delete a string at a given index" << endl;
    cout << " F   Search the list for a string" << endl;
    cout << " A   Display the result of assigment operator"<<endl;
    cout << " Q   Quit this test program" << endl;
}

void displayCopiedList(List original){
    List copy(original);
    copy.display(cout);
}

void displayAssignment(List original){
    List copy;
    copy = original;
    copy.display(cout);
}
