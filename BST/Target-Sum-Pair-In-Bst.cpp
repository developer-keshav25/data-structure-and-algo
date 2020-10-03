#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
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
Node *construct(int arr[])
{
    stack<Pair *> st;
    Node *root = new Node(arr[0]);
    Pair *rtp = new Pair(root, 1);
    st.push(rtp);
    int idx = 0;
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            idx++;
            if (arr[idx] != 0)
            {
                top->node->left = new Node(arr[idx]);
                Pair *lp = new Pair(top->node->left, 1);
                st.push(lp);
            }
            else
            {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if (top->state == 2)
        {
            idx++;
            if (arr[idx] != 0)
            {
                top->node->right = new Node(arr[idx]);
                Pair *rp = new Pair(top->node->right, 1);
                st.push(rp);
            }
            else
            {
                top->node->right = NULL;
            }
            top->state++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

int size(Node *node)
{
    if (node == NULL)
        return 0;
    int ls = size(node->left);
    int rs = size(node->right);
    return ls + rs + 1;
}

void display(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    string str = "";
    str += node->left == NULL ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == NULL ? "." : to_string(node->right->data) + "";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

bool find(Node *node, int val)
{
    if (node == NULL)
        return false;
    else if (node->data == val)
        return true;
    else if (val < node->data)
    {
        return find(node->left, val);
    }
    else
    {
        return find(node->right, val);
    }
}

void travelandPrint(Node *root, Node *node, int tar)
{
    if (node == NULL)
        return;
    travelandPrint(root, node->left, tar);
    int comp = tar - node->data;
    if (node->data < comp)
    {
        if (find(root, comp))
        {
            cout << node->data << " " << comp << '\n';
        }
    }
    travelandPrint(root, node->right, tar);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    string inp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        if (inp != "n")
        {
            arr[i] = stoi(inp);
        }
        else
            arr[i] = 0;
    }

    Node *root = construct(arr);
    int tar;
    cin >> tar;
    travelandPrint(root, root, tar);
    return 0;
}