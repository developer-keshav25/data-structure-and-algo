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

struct Pair
{
    Node *node;
    int state;
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

void iterativepreorderpostorder(Node *node)
{
    string pre = "", post= "";
    stack<Pair *> st;
    st.push(new Pair(node, -1));
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == -1)
        {
            pre += to_string(top->node->data) + string(" ");
            top->state++;
        }
        else if (top->state == top->node->children.size())
        {
            post += to_string(top->node->data) + string(" ");
            st.pop();
        }
        else
        {
            st.push(new Pair(top->node->children[top->state], -1));
            top->state++;
        }
    }
    cout << pre << '\n'
         << post;
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
    iterativepreorderpostorder(root);
    return 0;
}