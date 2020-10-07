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

int height(Node *root)
{
    if (root == NULL)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return std::max(lh, rh) + 1;
}

int Diameter1(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int ld = Diameter1(node->left);
    int rd = Diameter1(node->right);
    int f = height(node->left) + height(node->right) + 2;
    int dia = std::max(f, std::max(ld, rd));
    return dia;
}

static int dia = 0;

int CalculateDiaReturnHeight(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    int lh = CalculateDiaReturnHeight(node->left);
    int rh  = CalculateDiaReturnHeight(node->right); 
    if(lh+rh+2>dia){
        dia = lh+rh+2;
    }
    return max(lh,rh)+1;
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
    // cout<<Diameter1(root);
    CalculateDiaReturnHeight(root);
    cout<<dia;
    return 0;
}