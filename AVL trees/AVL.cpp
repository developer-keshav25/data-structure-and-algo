#include<iostream>
using namespace std;
class node{
    public:
    int key;
    int height;
    node*left,*right;
};
int successor(node*root){
    if(root->right!=NULL)
    return successor(root->right);
    return root->key;
}
int getheight(node*root){
    if(root==NULL)
    return 0;
    return root->height;
}
node* leftrotate(node*root){
    node*p = root->right;
    node*q = p->left;
    p->left = root;
    root->right = q;
    root->height = max(getheight(root->left), getheight(root->right)) + 1;  
    p->height = max(getheight(p->left), getheight(p->right)) + 1;
    return p;   
}
node*rightrotate(node*root){
    node*p = root->left;
    node*q = p->right;
    p->right = root;
    root->left = q;
    root->height = max(getheight(root->left), getheight(root->right)) + 1;  
    p->height = max(getheight(p->left), getheight(p->right)) + 1;
    return p;   
}

int getbalance(node*root){
    if(root==NULL)
    return 0;
    return getheight(root->left)-getheight(root->right);
}
node*newnode(int val){
    node*temp = new node();
    temp->key = val;
    temp->height = 1;
    temp->left=temp->right=NULL;
    return temp;
}
node* insert(node*root,int val){
    if(root==NULL){
    return newnode(val);
    }
    else if(val<root->key)
    root->left = insert(root->left,val);
    else
    root->right = insert(root->right,val);
    root->height = 1 + max(getheight(root->left),getheight(root->right));  
    
    int balance = getbalance(root);
    
    if(balance>1&&val<root->left->key)
    return rightrotate(root);
    
    if(balance<-1&&val>root->right->key)
    return leftrotate(root);
    
    if(balance>1&&val>root->left->key){
    root->left = leftrotate(root->left);
    return rightrotate(root);
    }
    
    if(balance<-1&&val<root->right->key){
    root->right = rightrotate(root->right);
    return leftrotate(root);
    }
return root;
}

node*deletion(node*root,int val){
    if(root==NULL)
    return root;
    else if(val<root->key)
    root->left = deletion(root->left,val);
    else if(val>root->key)
    root->right = deletion(root->right,val);
    else{
        if(root->left!=NULL && root->right!=NULL){
            int s = successor(root->left);
            root->key = s;
            root->left = deletion(root->left,s);
            return root;
        }
        else if(root->left!=NULL){
            return root->left;
        }
        else if(root->right!=NULL){
            return root->right;
        }
        else
        {
            return NULL;
        }
    }
     root->height = 1 + max(getheight(root->left),getheight(root->right));  
     int balance = getbalance(root);
     //left left case
     if (balance > 1 &&  getbalance(root->left) >= 0)  
        return rightrotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  getbalance(root->left) < 0)  
    {  
        root->left = leftrotate(root->left);  
        return rightrotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  getbalance(root->right) <= 0)  
        return leftrotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  getbalance(root->right) > 0)  
    {  
        root->right = rightrotate(root->right);  
        return leftrotate(root);  
    }
    return root;  
  
}

void inorder(node*root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
int main(){
    node *root=NULL;
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 60); 
    inorder(root);
    // cout<<'\n'<<"after deletion of "<<60<<": ";
    // deletion(root,60);
    // inorder(root);
    return 0;
}