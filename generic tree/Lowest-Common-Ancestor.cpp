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

int lca(Node *node, int d1, int d2)
{

    vector<int> path1 = nodeToRootPath(node, d1);
    vector<int> path2 = nodeToRootPath(node, d2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;
    while (i >= 0 && j >= 0 && path1[i] == path2[j])
    {
        i--;
        j--;
    }
    return path1[i + 1];
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
    int d1, d2;
    cin >> d1 >> d2;
    int ans = lca(root, d1, d2);
    cout << ans;
    return 0;
}