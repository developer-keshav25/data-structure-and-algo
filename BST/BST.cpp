#include<iostream>
using namespace std;
class node{
    int key;
    node*left,*right=NULL;
    public:
    node(){
        left=right=NULL;
    }
    node(int val){
        this->key = val;
        left=right=NULL;
    }
    node*insert(node*,int);
    bool find(node*,int);
    int sum(node*);
    void inorder(node*);
    int size(node*);
    int max(node*);
    int min(node*);
    node* deletetion(node*,int);
    bool check_balanced(node*);
    int height(node*);
};
node* node::insert(node*root,int val){
    if(root==NULL){
    return new node(val);
    }
    else if(val<root->key)
    root->left= insert(root->left,val);
    else
    root->right = insert(root->right,val);
    return root;
    
}
bool node::find(node*root,int val){
    if(root==NULL)
    return false;
    else if(root->key==val)
    return true;
    else if(val<root->key)
    return find(root->left,val);
    else 
    return find(root->right,val);
}
int node::sum(node*root){
    if(root==NULL)
    return 0;
    int ls = sum(root->left);
    int rs = sum(root->right);
    return ls+rs+root->key;
}
int node::size(node*root){
    if(root==NULL)
    return 0;
    int ls = size(root->left);
    int rs = size(root->right);
    return ls+rs+1;
}
int node::max(node*root){
    if(root->right!=NULL)
    return max(root->right);
    else
    return root->key;
    
}
int node::min(node*root){
    if(root->left!=NULL)
    return min(root->left);
    else
    return root->key;
    
}

void node::inorder(node*root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
node* node::deletetion(node*root,int val){
    if(root ==NULL)
    return root;
    else if(val<root->key)
    root->left = deletetion(root->left,val);
    else if(val>root->key)
    root->right = deletetion(root->right,val);
    else{
        if(root->left!=NULL&&root->right!=NULL){
            int x = max(root->left);
            root->key = x;
            root->left= deletetion(root->left,x);
            return root;
        }
        else if(root->left!=NULL){
            return root->left;
        }
        else if(root->right!=NULL){
            return root->right;
        }
        else{
                return NULL;
        }
    }
    return root;
}
int node::height(node*root){
    if(root==NULL)
    return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return std::max(lh,rh)+1;
}
bool node::check_balanced(node*root){
    if(root==NULL)
    return true;
    int lh = height(root->left);
    int rh= height(root->right);
    if(lh-rh<=-2||lh-rh>=2){
        return false;
    }
    return true;
}
int main(){
node b,*root =NULL ;
root = b.insert(root,60);
b.insert(root,50);
b.insert(root,40);
b.insert(root,90);
b.insert(root,70);
b.insert(root,45);
b.insert(root,30);
cout<<b.min(root)<<'\n';
cout<<b.sum(root)<<'\n';
cout<<b.max(root)<<'\n';
cout<<b.size(root)<<'\n';
if(b.find(root,30))
cout<<"true";
else
cout<<"false";
cout<<'\n';
b.inorder(root);
cout<<'\n';
b.deletetion(root,70);
// b.inorder(root);
cout<<b.height(root)<<'\n';
cout<<b.check_balanced(root);
return 0;
}