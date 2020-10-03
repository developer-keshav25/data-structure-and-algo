#include <iostream>
#include <stack>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->key = data;
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
void iterativePrePostInTraversal(Node *root)
{
    // stack<Node*>st;//my attempt preorder
    // st.push(root);
    // while(st.size()>0){
    //         Node*node = st.top();st.pop();
    //         cout<<node->key<<" ";
    //         if(node->right!=NULL)
    //         st.push(node->right);
    //         if(node->left!=NULL)
    //         st.push(node->left);

    // }

    string pre, in, post;
    stack<Pair *> st;
    st.push(new Pair(root, 1));
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            pre += to_string(top->node->key) + string(" ");
            top->state++;
            if (top->node->left != NULL)
            {
                st.push(new Pair(top->node->left, 1));
            }
        }
        else if (top->state == 2)
        {
            in += to_string(top->node->key) + string(" ");
            top->state++;
            if (top->node->right != NULL)
            {
                st.push(new Pair(top->node->right, 1));
            }
        }
        else
        {
            post += to_string(top->node->key) + string(" ");
            st.pop();
        }
    }
    cout << pre << endl
         << in << endl
         << post << endl;
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
    iterativePrePostInTraversal(root);
    return 0;
}