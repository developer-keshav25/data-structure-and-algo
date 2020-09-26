#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    node *next;
    node(int key)
    {
        this->key = key;
        next = NULL;
    }
};
class linkedlist
{
public:
    node *head;
    node *tail;
    int size;
    void addLast(int key)
    {
        if (this->size == 0)
        {
            this->head = this->tail = new node(key);
            this->size += 1;
        }
        else
        {
            this->tail->next = new node(key);
            this->tail = this->tail->next;
            this->size += 1;
        }
    }
    void display();
    int Size();
    void removeFirst();
    int getFirst();
    int getLast();
    int getAt(int);
    void addFirst(int);
    void addAt(int,int);
    void removeLast();
    void removeAt(int);
    void reverseDI();
    node* getnodeAt(int);
    void reversePI();
    int  kthFromLast(int); 
};
void linkedlist::display()
{
    node *temp = this->head;
    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

int linkedlist::Size()
{
    return this->size;
}

void linkedlist::removeFirst()
{
    if (this->size == 0)
        cout << "List is empty"<<endl;
    else if (this->size == 1){
        this->head = this->tail = NULL;
        this->size-=1;
    }
    else{
        this->head = this->head->next;
        this->size-=1;
    }
}

int linkedlist::getFirst(){
    if(this->size==0){
    cout<<"List is empty"<<endl;
    return -1;
    }
    return this->head->key;
}
int linkedlist::getLast(){
    if(this->size==0){
    cout<<"List is empty"<<endl;
    return -1;
    }
    return this->tail->key;
}
int linkedlist::getAt(int idx){
    if(this->size==0){
    cout<<"List is empty"<<endl;
    return -1;
    }
    else if(idx>=this->size){
        cout<<"Invalid arguments"<<endl;
        return -1;
    }
    else{
    node* temp = this->head;
    for(int i=0;i<idx;i++){
        temp = temp->next;
    }
    return temp->key;
    }
}
node* linkedlist::getnodeAt(int idx){
    node* temp = this->head;
    for(int i=0;i<idx;i++){
        temp = temp->next;
    }
    return temp;
}
void linkedlist::addFirst(int key){
    if(this->size==0){
    this->head = this->tail = new node(key);
    this->size+=1;
    }
    else{
        node* temp =  new node(key);
        temp->next = this->head;
        this->head = temp;
        this->size+=1;
    }
}
void linkedlist::addAt(int key,int idx){
    if(idx<0 || idx>this->size){
        cout<<"Invalid arguments"<<endl;
    }
    else if(idx==0)    {
        addFirst(key);
    }
    else if(idx==this->size){
        addLast(key);
    }
    else{
        node*ptr = this->head;
        for (int i = 0; i < idx-1; i++)
        {
            ptr = ptr->next; 
        }
        node *temp = new node(key);
        temp->next = ptr->next;
        ptr->next = temp;
        this->size+=1;
    }
    
}

void linkedlist::removeLast(){
    if(this->size==0)
    cout<< "List is empty"<<endl;
    else if(this->size==1){
        this->head = this->tail = NULL;
        size--;
    }
    else{
        node *head = this->head;
        for (int i = 0; i < size-2; i++)
        {
            head = head->next;
        }
        tail = head;
        head->next  =NULL;
        size--;
    }
}

void linkedlist::removeAt(int idx){
    if(idx<0 || idx>=size)
     cout<<"Invalid arguments"<<endl;
    else if(idx==0)
    removeFirst();
    else if(idx==size-1)
    removeLast();
    else{
        node*pre;
        node*head = this->head;
        for (int i = 0; i < idx; i++)
        {
            pre = head;
            head = head->next;
        }
        pre->next = head->next;
        head->next = NULL;
        size--;
    }
}

void linkedlist::reverseDI(){
    int i=0,j=size-1;
    while(i<j){
        node*left = getnodeAt(i);
        node*right = getnodeAt(j);
        swap(left->key,right->key);
        i++;
        j--;
    }
}

void linkedlist::reversePI(){
node*prev = NULL;
node*curr = head;
while(curr!=NULL){
    node *ocr = curr->next;
    curr->next =prev;
    prev = curr;
    curr = ocr;
}
node*temp = head;
head = tail;
tail = temp;
}

int linkedlist::kthFromLast(int k){
    node *prev= head;
    node*forw = head;
    for (int i = 0; i < k; i++)
    {
        forw=forw->next;
    }
    while(forw!=tail){
        prev=prev->next;
        forw=forw->next;
    }
    return prev->key;
    
}

void test(linkedlist list)
{

    node *temp = list.head;
    while (temp != NULL)
    {
        cout << temp->key << endl;
        temp = temp->next;
    }
    cout << list.size << endl;

    if (list.size > 0)
    {
        cout << list.tail->key;
    }
}

int main()
{
    linkedlist ll;
    ll.head = NULL;
    ll.tail = NULL;
    ll.size = 0;
    string input;
    cin >> input;
    while (input != "quit")
    {
        if (input == "addLast")
        {
            int x;
            cin >> x;
            ll.addLast(x);
        }
        if (input == "display")
            ll.display();
        if (input == "size")
            cout << ll.Size() << endl;
        if (input == "removeFirst")
            ll.removeFirst();
        if(input == "getLast"){
            int res = ll.getLast();
            if(res!=-1)
            cout<<res<<endl;
        }
        if(input == "getFirst"){
            int res = ll.getFirst();
            if(res!=-1)
            cout<<res<<endl;
        }
        if(input == "getAt"){
            int idx;
            cin>>idx;
            int res = ll.getAt(idx);
            if(res!=-1)
            cout<<res<<endl;
        }
        if(input == "addFirst"){
            int x;
            cin>>x;
            ll.addFirst(x);
        }
        if(input == "addAt"){
            int idx,x;
            cin>>idx>>x;
            ll.addAt(x,idx);
        }
        if(input == "removeLast")
        ll.removeLast();
        if(input == "removeAt"){
        int idx;cin>>idx;
        ll.removeAt(idx);
        }
        if(input == "reverseDI")
        ll.reverseDI();
        if(input == "reversePI")
        ll.reversePI();
        if(input == "kthFromEnd"){
            int k;cin>>k;
            cout<<ll.kthFromLast(k)<<endl;
        }
        cin >> input;
    }
    // test(ll);
    return 0;
}