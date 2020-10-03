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

int size(Node *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    for (auto child : root->children)
    {
        count += size(child);
    }
    return count + 1;
}

int Maximum(Node *root)
{
    if (root == NULL)
        return 0;
    int max = INT_MIN;
    for (auto child : root->children)
    {
        max = std::max(max, Maximum(child));
    }
    return std::max(max, root->data);
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int h = -1;
    for (auto child : root->children)
    {
        h = std::max(h, height(child));
    }
    return h + 1;
}

void Traversals(Node *root)
{
    cout << "Node Pre " << root->data << '\n';
    for (auto child : root->children)
    {
        cout << "Edge Pre " << root->data << "--" << child->data << '\n';
        Traversals(child);
        cout << "Edge Post " << root->data << "--" << child->data << '\n';
    }
    cout << "Node Post " << root->data << '\n';
}

void LevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        Node *rem = q.front();
        q.pop();
        cout << rem->data << " ";
        for (auto child : rem->children)
        {
            q.push(child);
        }
    }
    cout << ".";
}

void LevelOrderlinewise(Node *root)
{
    queue<Node *> mq;
    queue<Node *> cq;
    mq.push(root);
    while (mq.size() > 0)
    {
        Node *rem = mq.front();
        mq.pop();
        cout << rem->data << " ";
        for (auto child : rem->children)
        {
            cq.push(child);
        }
        if (mq.size() == 0)
        {
            mq = cq;
            cq = queue<Node *>();
            cout << '\n';
        }
    }
}

void LevelOrderzigzaglinewise(Node *root)
{
    stack<Node *> ms;
    stack<Node *> cs;
    ms.push(root);
    int level = 1;
    while (ms.size() > 0)
    {
        Node *rem = ms.top();
        ms.pop();
        cout << rem->data << " ";
        if (level % 2 == 1)
        {
            for (auto child : rem->children)
            {
                cs.push(child);
            }
        }
        else
        {
            for (int i = rem->children.size() - 1; i >= 0; --i)
            {
                Node *child = rem->children.at(i);
                cs.push(child);
            }
        }
        if (ms.size() == 0)
        {
            ms = cs;
            cs = stack<Node *>();
            level++;
            cout << '\n';
        }
    }
}

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


void mirror(Node*root){
    for(auto child:root->children){
        mirror(child);
    }
    reverse(root->children.begin(),root->children.end());
}

void RemoveLeaves(Node*root){
    for (int i = root->children.size()-1;i>=0;i--)
    {
        
        Node*child = root->children.at(i);
        if(child->children.size()==0){
            root->children.erase(root->children.begin()+i);
        }
    }
    for(auto child:root->children){
        RemoveLeaves(child);
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
    RemoveLeaves(root);
    display(root);
    return 0;
}