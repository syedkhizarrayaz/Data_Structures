#include <iostream>
#include <stdlib.h>
#include <stack>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int operator_precedence(char exp){ // operator precedence
    if(exp == '^'){ // highest
        return 3;
    }
    else if(exp == '/' || exp=='*'){
        return 2;
    }
    else if(exp == '+' || exp=='-'){ // lowest
        return 1;
    }
    else // if not any of them
        return 0;
}
void Postfix_exp(string exp){
    stack<char>operators; // stack
    string postfix; // final postfix
    char exp1; // character by character
    for(int i=0; i<exp.length(); i++){ // tarversing string
        exp1 = exp[i];
        if((exp1 >= 'A' && exp1<= 'Z') || (exp1>='a' && exp1<='z') || (exp1>='0' && exp1<='9')){ // if alphabet or numbers
            postfix = postfix + exp1;
        }
        else if(exp1 == '('){ // if open bracket
            operators.push(exp1);
        }
        else if(exp1 == ')'){ // if closed found pop all till open and put it in postfix
            while(operators.top() != '('){
                postfix = postfix + operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else{ // if operators
            while(!operators.empty() && operator_precedence(exp1) <= operator_precedence(operators.top())){
                postfix = postfix + operators.top(); // add in postfix till > operator if op in stack > op in string
                operators.pop();
            }
            operators.push(exp1); // next character
        }
    }
    while(!operators.empty()){ // if string finished put it in postfix till stack is empty
        postfix = postfix + operators.top();
        operators.pop();
    }
    cout << "Postfix: ";
    cout << postfix << endl; // print postfix
}
void prefix_exp(string exp){
    char exp1; // character by character
    stack<char> operators; // stack
    string prefix; // prefix
    reverse(exp.begin(), exp.end()); // reverse it
    for(int k=0; k<exp.length(); k++){ // reverse brackets
        if(exp[k] == '('){
            exp[k] = ')';
        }
        else if(exp[k] == ')'){
            exp[k] = '(';
        }
    }
    for(int i=0; i<exp.length(); i++){ // tarverse
        exp1 = exp[i];
        if((exp1>='A' && exp1<='Z') || (exp1>='a' && exp1<='z') || (exp1>='0' && exp1<='9')){ // if alphabets or numbers
            prefix = prefix + exp1;
        }
        else if(exp1 == '('){ // if open bracket
            operators.push(exp1);
        }
        else if(exp1 == ')'){ //if closed found pop till open and put it in prefix
            while(operators.top() != '('){
                prefix = prefix + operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else{ // if operators
            while(!operators.empty() && operator_precedence(exp1) <= operator_precedence(operators.top())){
                prefix = prefix + operators.top(); // < precedence in string pop and put till equals or lower precedence
                operators.pop();
            }
            operators.push(exp1); // next character
        }
    }
    while(!operators.empty()){ // if exp finished empty stack to prefix
        prefix = prefix + operators.top();
        operators.pop();
    }
    cout << "Postfix: ";
    reverse(prefix.begin(), prefix.end()); // reverse expression
    cout << prefix << endl; // print it
}
int main(){
    string exp;
    cout << "Input Infix Expression: " << endl;
    cin >> exp; // expression
    Postfix_exp(); // post fix
    prefix_exp(); // pre fix
    return 0;
}