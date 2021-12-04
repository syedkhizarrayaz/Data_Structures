#include <iostream>
#include <stdlib.h>

using namespace std;

struct circular_ll{ // structure of linkedlist
    int data; // data
    circular_ll* Node; // node 
};
struct circular_ll* head = NULL; // head pointer
int counter = 0; // counter for mid value
void insertion_mid(int data){
    struct circular_ll* temp; // call cll;
    temp = new circular_ll(); 
    temp->data = data; // data in data
    if(head == NULL){ // if empty
        head = temp; // head is new node
        temp->Node = head; // node has address of head
    }
    counter++; // counter increases
    if(head != NULL){ // if not empty
        int mid; // mid value
        struct circular_ll* temp1 = NULL; // head pointer 
        struct circular_ll* inserter= NULL; // traverser pointer
        int c = counter % 2; // find mod 
        temp1 = head; // set head to temp1 pointer
        if(c != 0){ // if not even
            mid = (counter/2)+1; // mid value
            for(int i=0; i<mid; i++){ // travsersing till mid of linked list
                inserter = temp1; // inserter pointer
                temp1 = temp1->Node; // next node
               
            }
            inserter->Node = temp; // inserter node has temp address
            temp->Node = temp1; // temp has address of next node
        }
        if(c == 0){ // if even
            mid = counter/2; // find mid
            for(int j=0; j<mid; j++){ // traverse till mid of linked list
                inserter = temp1; // inserter pointer
                temp1=temp1->Node; // next node
            }
            inserter->Node = temp; // inserter has address new node 
            temp->Node = temp1;  // new node has address of next node
        }
    }
    counter++; // counter increases
}
void display(){
    struct circular_ll* temp; // call cll
    temp = head; // set head
    cout << temp->data << "-> "; // print head data 
    temp = temp->Node; // go to next node
    while(temp != head){ // untill last node pointer arises
        cout << temp->data; // print data
        temp = temp->Node; // go to next node
        cout << "-> ";
    }
}
int main(){
    insertion_mid(68); // insertion
    insertion_mid(55);
    insertion_mid(88);
    display(); // display
    return 0;
}