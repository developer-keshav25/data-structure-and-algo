#include<iostream>
#include<list>
using namespace std;
class LLToStackAdapter{
    public:
    list<int> ll;
    int size();
    void push(int);
    int pop();
    int top();
};
void LLToStackAdapter::push(int val){
    ll.push_back(val);
}

int LLToStackAdapter::pop(){
    int x = ll.back();
    ll.pop_back();
    return x;
}
int LLToStackAdapter::size(){
return ll.size();
}
int LLToStackAdapter::top(){
return ll.back();
}
int main(){
    LLToStackAdapter llstack;
    string input;
    while (input!="quit")
    {
        if(input=="push"){
            int val;cin>>val;
            llstack.push(val);
        }
        if(input=="pop")
        cout<<llstack.pop()<<endl;
        if(input=="size")
        cout<<llstack.size()<<endl;
        if(input=="top")
        cout<<llstack.top()<<endl;
        cin>>input;
    }
    
return 0;
}