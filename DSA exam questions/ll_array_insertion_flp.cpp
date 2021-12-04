#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

auto strat = steady_clock::now(); // time start
struct linked_list{ // linked list structure
    int data; // data
    linked_list* Node; // next node
};
struct linked_list* head= NULL; // head for first node reference
void insertion(int data){ 
    struct linked_list* temp; // call linked list
    temp = new linked_list();
    if(head != NULL){
    temp->data = data; // data in data
    temp->Node = head; // node has address of head
    head = temp;// now new head is new node
    }else{
        temp->data = data;
        temp->Node = NULL;
        head = temp;
    }
}
int main(){
    insertion(7);
    insertion(7);
    auto end = steady_clock::now(); // time stop
    auto duration = duration_cast<nanoseconds>(end-strat).count(); // calculate duration
    cout << "time taken: " << duration << "sec " << endl; // print time
    struct linked_list* temp; // call linked lsit
    temp=head; // call head
    while(temp != NULL){ // until temp not null
        cout << temp->data << "-> "; // print data
        temp= temp->Node; // go to next node
    }
    auto start2 = steady_clock::now(); // time 2 for array
    int array[3]; // create array
    for(int i=0; i<3; i++){ // fill array
        array[i] = 66;
    }
    for (int j=0; j<=0; j++){ // insert at start of array
        array[j] = 6;
    }
    auto end1 = steady_clock::now(); // end time
    auto duration1 = duration_cast<nanoseconds>(end1-start2).count(); // calculate time
    cout << "time taken: " << duration1/1e9 << "seconds " << endl; // print time
    for(int k = 0; k<3; k++){ // print array
        cout << array[k] << " " ;
    }
    return 0; 
}