#include<iostream>
#include<list>
#include<stack>
#include<string.h>
using namespace std;
int operation(int a ,int b,char op){
    if(op=='+')
    return a+b;
    else if(op=='-')
    return a-b;
    else if(op=='*')
    return a*b;
    else
    return a/b; 
}
int precedence(char op){
    if(op=='+')
    return 1;
    else if(op=='-')
    return 1;
    else if(op=='*')
    return 2;
    else
    return 2; 
}
int evaluation(string input){
    stack<int>operands;
    stack<char>operators;
    for(char itr:input){
        if(itr==')'){
            while(operators.top()!='('){
            char op = operators.top();
            operators.pop();
            int a = operands.top();
            operands.pop();
            int b =operands.top();
            operands.pop();
            operands.push(operation(b,a,op));
            }
            operators.pop();
        }
        else if(itr=='+'||itr=='*'||itr=='/'||itr=='-'){
            while(operators.size()>0&&operators.top()!='('&&precedence(itr)<=precedence(operators.top())){
            char op = operators.top();
            operators.pop();
            int a = operands.top();
            operands.pop();
            int b =operands.top();
            operands.pop();
            operands.push(operation(b,a,op));
            }
            operators.push(itr);
        }
        else if(itr=='(')
        operators.push(itr);
        else if(isdigit(itr))
        operands.push(itr-'0');

    }
    while (operators.size()!=0)
    {
        char op = operators.top();
        operators.pop();
        int a = operands.top();
        operands.pop();
        int b =operands.top();
        operands.pop();
        operands.push(operation(b,a,op));
    }
    
    return operands.top();
}
int main(){
    string rawInput;
   getline(cin,rawInput,'\n');
    cout<<evaluation(rawInput);
return 0;
}