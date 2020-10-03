#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include<bits/stdc++.h>
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

struct BSTPair{
    bool isBST;
    int min;
    int max;
};
BSTPair IsBst(Node*root){
    if(root==NULL){
        BSTPair bp;
        bp.max = INT_MIN;
        bp.min = INT_MAX;
        bp.isBST = true;
        return bp;
    }
    BSTPair lp = IsBst(root->left);
    BSTPair rp = IsBst(root->right);
    BSTPair mp;
    mp.isBST = lp.isBST&&rp.isBST&&(root->key>=lp.max&&root->key<=rp.min);
    mp.min = std::min(lp.min,root->key);
    mp.max = std::max(rp.max,root->key);
    return mp;
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
    BSTPair res = IsBst(root); 
    if(res.isBST)
    cout<<"true";
    else
    cout<<"false";
    return 0;
}