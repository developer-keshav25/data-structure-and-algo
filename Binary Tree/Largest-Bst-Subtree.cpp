#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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
void display(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    string str = "";
    str += node->left == NULL ? "." : to_string(node->left->key) + "";
    str += " <- " + to_string(node->key) + " -> ";
    str += node->right == NULL ? "." : to_string(node->right->key) + "";
    cout << str << endl;

    display(node->left);
    display(node->right);
}
struct BSTPair{
    bool isBST; //if bst or not
    int min; //min of bst
    int max;//max of bst
    Node* lbstr;//root of largest bst
    int lbsts;//size of largest bst
};
BSTPair IsBst(Node*root){
    if(root==NULL){
        BSTPair bp;
        bp.max = INT32_MIN;
        bp.min = INT32_MAX;
        bp.isBST = true;
        bp.lbstr = NULL;
        bp.lbsts = 0;
        return bp;
    }
    BSTPair lp = IsBst(root->left);
    BSTPair rp = IsBst(root->right);
    BSTPair mp;
    mp.isBST = lp.isBST&&rp.isBST&&(root->key>=lp.max&&root->key<=rp.min);
    mp.min = std::min(lp.min,root->key);
    mp.max = std::max(rp.max,root->key);
    if(mp.isBST){
        mp.lbstr = root;
        mp.lbsts = lp.lbsts + rp.lbsts +1;
    }
    else if (lp.lbsts>rp.lbsts)
    {
        mp.lbstr = lp.lbstr;
        mp.lbsts = lp.lbsts;
    }
    else{
        mp.lbstr = rp.lbstr;
        mp.lbsts = rp.lbsts;
    }
    
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
    cout<<res.lbstr->key<<"@"<<res.lbsts; 
    return 0;
}