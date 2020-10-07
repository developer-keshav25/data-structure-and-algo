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

bool are_trees_mirror_in_shape(Node *node1, Node *node2)
{
    if (node1->children.size() != node2->children.size())
    {
        return false;
    }
    for (int i = 0,j= node2->children.size()-1; i < node1->children.size()&&j>=0; i++,j--)
    {
        Node *c1 = node1->children[i];
        Node *c2 = node2->children[j];
        if (are_trees_mirror_in_shape(c1, c2) == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Node *root1, *root2 = NULL;
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
    cin >> n;
    st = stack<Node *>();
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
                root2 = t;
            }
            st.push(t);
        }
    }
    if(are_trees_mirror_in_shape(root1,root2))
    cout<<"true";
    else cout<<"false";
    return 0;
}