// I/O in the question was not matching
#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
class Customstack{
public:
int *data;
int tos;
int len;
Customstack(int cap){
    data = new int[cap];
    tos = -1;
    len  = cap;
}
int size(){
    return tos+1;
}
void push(int val){
    if(tos==len-1)
    cout<<"stack overflow"<<'\n';
    else{
    ++tos;
    data[tos] = val;}

}
void display(){
    for (int i = tos; i >=0; --i)
    {
        cout<<data[i]<<" ";
    }
    
}
int pop(){
    if(tos==-1){
    cout<<"stack underflow"<<'\n';
    return -1;
    }
    else{
    int t = data[tos];
    --tos;
    cout<<t<<'\n';
    return t;
    }
}
int top(){
    if(tos==-1){
    cout<<"stack underflow"<<'\n';
    return -1;
    }
    else{
    cout<<data[tos]<<'\n';
    return data[tos];
    }
}
};
int main(){
int n;
cin>>n;
Customstack stack(n);
string str;
cin>>str;
while (str!="quit")
{
    if(str=="display"){
    stack.display();
    cout<<'\n';}
    else if(str=="pop")
    stack.pop();
    else if(str=="top")
    stack.top();
    else if(str=="size")
    cout<<stack.size()<<'\n';
    else if (str=="push"){
        int x;
        cin>>x;
        stack.push(x);
    }
    cin>>str;
}

return 0;
}