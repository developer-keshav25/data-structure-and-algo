#include<iostream>
#include<list>
#include<string.h>
using namespace std;
list<char>stack;
void duplicate(list<char> s){
for(char itr:s){
        if(itr==')'){
            if(stack.back()=='('){
            cout<<"true";
            return;
            }
            else{
                while(stack.back()!='(')
                    stack.pop_back();
                stack.pop_back();
            }
        }
        else 
        stack.push_back(itr);
    }
 cout<<"false";
 return;
}

int main(){
    char ch;
    list<char>input;
    while (cin.get(ch)&&ch!='\n')
    {
        input.push_back(ch);
    }
    duplicate(input);
}