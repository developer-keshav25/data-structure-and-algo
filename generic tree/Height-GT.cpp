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
    cout << height(root);
    return 0;
}