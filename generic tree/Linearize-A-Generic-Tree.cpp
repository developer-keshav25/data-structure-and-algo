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

Node *getTail(Node *node)
{
    while (node->children.size() == 1)
    {
        node = node->children[0];
    }
    return node;
}

void linearize(Node *node)
{
    for (auto child : node->children)
    {
        linearize(child);
    }
    while (node->children.size() > 1)
    {
        Node *lc = node->children[node->children.size() - 1];
        node->children.pop_back();
        Node *sl = node->children[node->children.size() - 1];
        Node *slt = getTail(sl);
        slt->children.push_back(lc);
    }
}

int main()
{
    Node *root1 = NULL;
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
                root1 = t;
            }
            st.push(t);
        }
    }

    linearize(root1);
    display(root1);
    return 0;
}