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

vector<int> nodeToRootPath(Node *node, int val)
{
    if (node->data == val)
    {
        vector<int> list;
        list.push_back(node->data);
        return list;
    }
    for (auto child : node->children)
    {
        vector<int> ptc = nodeToRootPath(child, val);
        if (ptc.size() > 0)
        {
            ptc.push_back(node->data);
            return ptc;
        }
    }
    return vector<int>();
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
    vector<int> ans = nodeToRootPath(root, val);
    if(ans.size()==0){
        cout<<"[]";
        return 0;
    }
    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ", ";
    }
    cout << ans.back();
    cout << "]";
    return 0;
}