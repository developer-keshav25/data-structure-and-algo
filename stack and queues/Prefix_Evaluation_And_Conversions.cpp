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
    stack<string>post;
    for(char itr:input){
        if(itr=='+'||itr=='*'||itr=='/'||itr=='-'){
            int v2 = operands.top();operands.pop();
            int v1 = operands.top();operands.pop();
            operands.push(operation(v2,v1,itr));
            string v4 = in.top();in.pop();
            string v3 = in.top(); in.pop();
            string ival = "("+v4+string(1,itr)+v3+string(")");
            in.push(ival);
            v4 = post.top();post.pop();
            v3 = post.top(); post.pop();
            ival = v4+v3+string(1,itr);
            post.push(ival);
        }
        else if(isdigit(itr)){
        operands.push(itr-'0');
        post.push(string(1,itr));
        in.push(string(1,itr));
        }

    }
  cout<<operands.top()<<'\n'<<in.top()<<'\n'<<post.top();

}
int main(){
    string rawInput;
    getline(cin,rawInput,'\n');
    string rev = string(rawInput.rbegin(),rawInput.rend());
    evaluation(rev);
return 0;
}