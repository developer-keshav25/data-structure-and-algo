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
void printKlevelsdown(Node*root,int k,Node*block){
    if(root==NULL||k<0||root==block)
    return;
    if(k==0){
    cout<<root->key<<'\n';
     return;
    }
    printKlevelsdown(root->left,k-1,block);
    printKlevelsdown(root->right,k-1,block);
}
static vector<Node*>path;

bool Find(Node *root, int val)
{
    if (root == NULL)
        return false;
    if (root->key == val){
        path.push_back(root);
        return true;
    }
    bool filc = Find(root->left, val);
    if (filc){
        path.push_back(root);
        return true;
    }
    bool firc = Find(root->right, val);
    if (firc){
        path.push_back(root);
        return true;
    }
    return false;
}

void printKNodesFar(Node*root,int data ,int k){
    path = vector<Node*>();
    Find(root,data);
    for (int i = 0; i < path.size(); i++)
    {
        printKlevelsdown(path[i],k-i,i==0?NULL:path[i-1]);
    }
    
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
    int data,k;cin>>data>>k;
    printKNodesFar(root,data,k);
    return 0;
}