#include<iostream>
#include<string>
#include <bits/stdc++.h> 
using namespace std;
struct node{
    int key;
    node*next;
    node(int key){
        this->key = key;
        next  = NULL;
    }
};
class linkedlist{
public:
node*head;
node*tail;
int size;
void addLast(int key){
if(this->size==0){
    this->head = this->tail = new node(key);
    this->size+=1;    
}
else{
this->tail->next = new node(key);
this->tail = this->tail->next;
this->size+=1;
}
}
void display();
int Size();
};
void linkedlist::display(){
    node*temp = this->head;
    while (temp!=NULL)
    {
        cout<<temp->key<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int linkedlist::Size(){
    return this->size;
}
void test(linkedlist list){

    node *temp = list.head;
    while(temp!=NULL){
        cout<<temp->key<<endl;
        temp= temp->next;
    }
    cout<<list.size<<endl;

    if (list.size > 0) {
      cout<<list.tail->key;
    } 
}

int main(){
linkedlist ll;
ll.head = NULL;
ll.tail = NULL;
ll.size = 0;
string input;
cin>>input;
while (input!="quit")
{
    if(input == "addLast"){
    int x;
    cin>>x;
    ll.addLast(x);
    }
    if(input == "display")
    ll.display();
    if(input=="size")
    cout<<ll.Size()<<endl;
    cin>>input;
    
}
// test(ll);
return 0;
}