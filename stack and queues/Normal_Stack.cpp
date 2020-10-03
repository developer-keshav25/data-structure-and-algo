// I/O in the question was not matching
#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
class Customstack{
int *data;
int tos;
int len;
public:
Customstack(int cap){
    data = new int[cap];
    tos = -1;
    this->len  = cap;
}
int size(){
    return tos+1;
}
void push(int val){
    if(tos==len-1)
    cout<<"Stack overflow"<<'\n';
    else{
    ++tos;
    data[tos] = val;}

}
void display(){
    for (int i = tos; i >=0; --i)
    {
        cout<<data[i]<<" ";
    }
   cout<<'\n'; 
}
int pop(){
    if(tos==-1){
    cout<<"Stack underflow"<<'\n';
    return -1;
    }
    int t = data[tos];
    --tos;
    return t;
}
int top(){
    if(tos==-1){
    cout<<"Stack underflow"<<'\n';
    return -1;
    }
    return data[tos];
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
    if(str=="display")
    stack.display();
    else if(str=="pop"){
    int x = stack.pop();
    if(x!=-1)
    cout<<x<<'\n';
    }
    else if(str=="top"){
    int x = stack.top();
    if(x!=-1)
    cout<<x<<'\n';
    }
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