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

void display(Node *root)
{
    string str = to_string(root->data) + " -> ";
    for (auto child : root->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << '\n';

    for (auto child : root->children)
    {
        display(child);
    }
}

static int Ceil;
static int Floor;
void CeilAndFloor(Node *node, int data)
{
    if (node->data > data)
    {
        if (node->data < Ceil)
        {
            Ceil = node->data;
        }
    }
    if (node->data < data)
    {
        if (node->data > Floor)
        {
            Floor = node->data;
        }
    }

    for (auto child : node->children)
    {
        CeilAndFloor(child, data);
    }
}

int kthlargestelement(Node*node,int k){
    Floor = INT32_MIN;
    int factor  = INT32_MAX;
    for (int i = 0; i < k; i++)
    {
         CeilAndFloor(node,factor);
         factor = Floor;
         Floor = INT32_MIN;

    }
    return factor;
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
    int k;
    cin >> k;
    int kthlargest = kthlargestelement(root,k);
    cout<<kthlargest;
    return 0;
}