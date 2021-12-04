#include <iostream>
#include <stdlib.h>

using namespace std;

struct linked_list{ // structure of linked list
    int data; // data
    linked_list* Node; // node
};
struct linked_list* head = NULL; // head first node pointer
void insertion(int data){
    struct linked_list* temp; // call linkedlist
    temp = new linked_list();
    if(head != NULL){ // if already has an element
    temp->data = data; // data in data
    temp->Node = head; // node has head address
    head = temp; // new node is head
    }else{
        temp->data = data; // data
        temp->Node = NULL; // node null
        head = temp; // head is first node
    }
}
void display(){
    struct linked_list* temp; //call linkedlist
    temp = head; // call head
    if(temp == NULL){ // if null means empty
        cout << "Linked list is empty " << endl;
    }else{
        while(temp !=NULL){ // until not empty
            cout << temp->data << " -> "; // temp data
            temp = temp->Node; // go to next node
        }
    }
}
int main(){
    insertion(66);
    insertion(667);
    insertion(664);
    insertion(6);
    insertion(64);
    insertion(86);
    insertion(76);
    insertion(16);
    insertion(669);
    insertion(666);
    display();
    return 0;
}