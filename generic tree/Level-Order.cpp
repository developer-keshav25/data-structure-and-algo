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

void Traversals(Node *root)
{
    cout << "Node Pre " << root->data << '\n';
    for (auto child : root->children)
    {
        cout << "Edge Pre " << root->data << "--" << child->data << '\n';
        Traversals(child);
        cout << "Edge Post " << root->data << "--" << child->data << '\n';
    }
    cout << "Node Post " << root->data << '\n';
}

void LevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        Node *rem = q.front();
        q.pop();
        cout << rem->data << " ";
        for (auto child : rem->children)
        {
            q.push(child);
        }
    }
    cout<<".";
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
    LevelOrder(root);
    return 0;
}