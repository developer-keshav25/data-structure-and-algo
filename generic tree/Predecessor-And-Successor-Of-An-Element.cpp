#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    vector<Node *> children;
    Node(int data)
    {
        this->data = data;
    }
};
void display(Node*root){
    string str = to_string(root->data) + " -> ";
    for (auto child : root->children) {
      str += to_string(child->data) + ", ";
    }
    str += ".";
    cout<<str<<'\n';

    for (auto child : root->children) {
      display(child);
    }
}


static Node* predecessor = NULL;
static Node* successor  = NULL;
static int state = 0;
void predecessorAndSuccessor(Node *node, int data)
{
    if (state == 0)
    {
        if (node->data == data)
        {
            state = 1;
        }
        else
        {
            predecessor = node;
        }
    }
    else if(state==1)
    {
        successor = node;
        state = 2;
    }
    

    for (auto child : node->children)
    {
        predecessorAndSuccessor(child, data);
    }
}

int main()
{
    Node *root = NULL;
    stack<Node *> st;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = new Node(x);
            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }

    int val;cin>>val;
    predecessorAndSuccessor(root,val);
    if(predecessor == NULL){
      cout<<"Predecessor = Not found"<<'\n';
    } else {
      cout<<"Predecessor = "<<predecessor->data<<'\n';
    }

    if(successor == NULL){
      cout<<"Successor = Not found"<<'\n';
    } else {
      cout<<"Successor = "<<successor->data<<'\n';
    }
    return 0;
}