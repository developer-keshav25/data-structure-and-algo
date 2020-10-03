#include <iostream>
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
    stack<Pair*> st;
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
void preorder(Node*root){
    if(root==NULL)
    return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->left);
}
int size(Node*root){
    if(root==NULL)
    return 0;
    int count = size(root->left)+size(root->right);
    return count+1;
}
int sum(Node*root){
    if(root==NULL)
    return 0;
    int count = sum(root->left)+sum(root->right);
    return count+root->key;
}
int height(Node*root){
    if(root==NULL)
    return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return std::max(lh,rh)+1;
}
int max(Node*root){
 if(root==NULL)
 return 0;
 int lmax = max(root->left);
 int rmax = max(root->right);
 return std::max(root->key,std::max(lmax,rmax));

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
    
    Node*root = construct(arr);
    cout<<size(root)<<endl;
    cout<<sum(root)<<endl;
    cout<<max(root)<<endl;
    cout<<height(root)-1<<endl;
    return 0;
}