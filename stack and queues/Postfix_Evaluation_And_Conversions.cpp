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

void evaluation(string input){
    stack<int>operands;
    stack<string>in;
    stack<string>pre;
    for(char itr:input){
        if(itr=='+'||itr=='*'||itr=='/'||itr=='-'){
            int v2 = operands.top();operands.pop();
            int v1 = operands.top();operands.pop();
            operands.push(operation(v1,v2,itr));
            string v4 = in.top();in.pop();
            string v3 = in.top(); in.pop();
            string ival = "("+v3+string(1,itr)+v4+string(")");
            in.push(ival);
            v4 = pre.top();pre.pop();
            v3 = pre.top(); pre.pop();
            ival = string(1,itr)+v3+v4;
            pre.push(ival);
        }
        else if(isdigit(itr)){
        operands.push(itr-'0');
        pre.push(string(1,itr));
        in.push(string(1,itr));
        }

    }
  cout<<operands.top()<<'\n'<<in.top()<<'\n'<<pre.top();

}
int main(){
    string rawInput;
    getline(cin,rawInput,'\n');
    evaluation(rawInput);
return 0;
}