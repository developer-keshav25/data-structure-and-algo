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
static int state;
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
    int val;
    cin >> val;
    Ceil = INT32_MAX;
    Floor = INT32_MIN;
    CeilAndFloor(root, val);
    cout << "CEIL = " << Ceil << '\n';
    cout << "FLOOR = " << Floor << '\n';
    return 0;
}