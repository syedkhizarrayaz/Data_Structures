#include <iostream>
#include <stdlib.h>

using namespace std;

struct doubly_ll{ // structure of double linked list
    string name;
    string phoneno;
    doubly_ll* next;
    doubly_ll* previous;
};
struct doubly_ll* head; // head pointer
void insertion(string n, string pn){
    struct doubly_ll* temp; // call double linked list
    temp = new doubly_ll();
    temp->name = n; // name
    temp->phoneno = pn; // phone no
    if(head == NULL){ // if empty
        temp->next = head; // next has head address
        temp->previous = head; // previous has head address
        head = temp; // head is new node
    }else{
        temp->next = head; // next node' next has previous head addeess
        temp->previous = head; // next node's previous has last node address
        head = temp; // new head is new node
    }
}
void deletion(){
    struct doubly_ll* temp; // call doubly linked list
    struct doubly_ll* temp1; // call doubly linked list
    temp = head; // head
    temp1 = temp->next; // next node than head
    if(temp == NULL){ // if empty
        cout << "Empty " << endl;
    }else{
        head = temp1; // head is now next node
        temp->next = NULL; // empty deletion pointers
        temp->previous = NULL; // empty pointers
        free(temp); // free space
    }
}
void display(){
    struct doubly_ll* temp; // call doubly linked list
    temp = head; // head 
    cout << "Name: "<< temp->name<< " Phone no: " << temp->phoneno << "-> "; // print details
    temp = temp->next; // go to next node
    while(temp != head){ // until head pointer comes
        cout << " Name: " << temp->name << " Phone no: " << temp->phoneno << "-> "; // print details
        temp = temp->next; // go to next node
    }
}
int main(){
    insertion("Jamal", "011714"); // insert
    insertion("Khan", "021487");
    deletion(); // delete
    display(); // display
    return 0;
}