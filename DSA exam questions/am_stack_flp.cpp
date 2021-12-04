#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

int main(){
    stack<int> st; // stack 
    int a,b; // int
    cout << "Enter 1st number: " << endl;
    cin >> a; // input 1st number
    cout << "Enter 2nd number: " << endl;
    cin >> b; // input 2nd number
    st.push(a); // push
    st.push(b);
    int c,d; // int
    c = st.top(); // take top of stack
    st.pop(); // pop
    d = st.top(); // take top of stack
    st.pop(); // pop
    cout << "Multiplication " << c*d << endl;
    cout << "Adition " << c+d << endl;
    return 0;
}