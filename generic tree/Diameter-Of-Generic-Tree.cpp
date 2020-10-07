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

static int dia = 0;
int CalculateDiaReturnHeight(Node *node)
{
    int dch = -1;
    int sdcht = -1;
    for (auto child : node->children)
    {
        int ch = CalculateDiaReturnHeight(child);
        if (ch > dch)
        {
            sdcht = dch;
            dch = ch;
        }
        else if (ch > sdcht)
        {
            sdcht = ch;
        }
    }
    if (dch + sdcht + 2 > dia)
    {
        dia = dch + sdcht + 2;
    }

    return dch + 1;
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
  
    CalculateDiaReturnHeight(root1);
    cout<<dia;
    return 0;
}