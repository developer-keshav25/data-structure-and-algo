#include<iostream>
#include<list>
#include<string.h>
using namespace std;
list<char>stack;
void duplicate(list<char> s){
for(char itr:s){
        if(itr==')'){
            if(stack.size()==0){
            cout<<"false";
            return;
            }
            else{
                if(stack.back()!='('){
                cout<<"false";
                return;}
                else
                stack.pop_back();
            }
        }
        else if(itr=='}'){
            if(stack.size()==0){
            cout<<"false";
            return;
            }
            else{
                if(stack.back()!='{'){
                cout<<"false";
                return;}
                else
                stack.pop_back();
            }
        }
        if(itr==']'){
            if(stack.size()==0){
            cout<<"false";
            return;
            }
            else{
                if(stack.back()!='['){
                cout<<"false";
                return;}
                else
                stack.pop_back();
            }
        }
        else if(itr=='('||itr=='['||itr=='{') 
        stack.push_back(itr);
    }
 if(stack.size()==0)
 cout<<"true";
else
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