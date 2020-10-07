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

int sumoftree(Node *node)
{
    if (node == NULL)
        return 0;
    int total = 0;
    for (auto child : node->children)
    {
        total += sumoftree(child);
    }
    return total + node->data;
}
static int Sum;
static Node*res;

void Node_of_max_subtree(Node*node){
    int cns = sumoftree(node);//sum of subtree of current node
    if(cns>Sum){
        Sum  = cns;
        res = node;
    }
    for (auto child:node->children)
    {
        Node_of_max_subtree(child);
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
    Sum = INT32_MIN;
    res = NULL;
    Node_of_max_subtree(root1);
    cout<<res->data<<"@"<<Sum;
    
    return 0;
}