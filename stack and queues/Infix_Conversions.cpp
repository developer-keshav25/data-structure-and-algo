// for string concatenation we have to covert them to string datatype and 
// to covert char to string we have to use string constructor
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int precedence(char op){
    if(op=='+')
    return 1;
    else if(op=='-')
    return 1;
    else if(op=='*')
    return 2;
    else
    return 2; 
}
void topostfix(string infix){
    stack<string>post;
    stack<string>pre;
    stack<char>op;
    for(char ch:infix){
        if(ch=='+'||ch=='-'||ch=='/'||ch=='*'){
            string v1,v2;
            while (op.size()>0&&op.top()!='('&&precedence(ch)<=precedence(op.top()))
            {
                char c = op.top();
                op.pop();
                v1 = post.top();
                post.pop();
                v2 = post.top();
                post.pop();
                string f = string(v2)+string(v1)+string(1,c);
                post.push(f);
                v1 = pre.top();
                pre.pop();
                v2 = pre.top();
                pre.pop();
                f = string(1,c)+string(v2)+string(v1);
                pre.push(f);
            }
            op.push(ch);
        }

        else if(ch==')'){
            string v1,v2;
            while(op.top()!='('){
                char c = op.top();
                op.pop();
                v1 = post.top();
                post.pop();
                v2 = post.top();
                post.pop();
                string f = string(v2)+string(v1)+string(1,c);
                post.push(f);
                v1 = pre.top();
                pre.pop();
                v2 = pre.top();
                pre.pop();
                f = string(1,c)+string(v2)+string(v1);
                pre.push(f);
            }
            op.pop();
        }
        else if(ch=='(')
        op.push(ch);
        else if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')){
        post.push(string(1,ch));
        pre.push(string(1,ch));
        }
        
    }
    while (op.size()!=0)
    {   string v1,v2;
        char c = op.top();
        op.pop();
        v1 = post.top();
        post.pop();
        v2 = post.top();
        post.pop();
        string f = string(v2)+string(v1)+string(1,c);
        post.push(f);
        v1 = pre.top();
        pre.pop();
        v2 = pre.top();
        pre.pop();
        f = string(1,c)+string(v2)+string(v1);
        pre.push(f);
    }
    cout<<post.top()<<'\n'<<pre.top();
}

int main(){
string rawInput;
getline(cin,rawInput);
topostfix(rawInput);
return 0;
}