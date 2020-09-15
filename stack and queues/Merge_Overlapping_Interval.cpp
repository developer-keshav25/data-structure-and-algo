#include<iostream>
#include <bits/stdc++.h>  
using namespace std;
class pairs{
    public:
    int st;
    int et;
    pairs(){}
    pairs(int st,int et){
        this->st=st;
        this->et=et;
    }
};
bool compare(pairs a, pairs b){
    if(a.st==b.st)
    return a.et-b.et;
    else
    return a.st<b.st;
}
int main(){
int n;
cin>>n;
int st;
int et;
pairs *pair = new pairs[n];
for (int i = 0; i < n; i++)
{
    cin>>st>>et;
    pair[i] = pairs(st,et);
}
std::sort(pair,pair+n,compare);
stack<pairs>stack1;
for (int i = 0; i < n; i++)
{
    if(i==0)
    stack1.push(pair[i]);
    else{
        if(pair[i].st>stack1.top().et)
        stack1.push(pair[i]);
        else
        stack1.top().et = std::max(stack1.top().et,pair[i].et);
        
    }
}
stack<pairs>res;
while(stack1.size()>0){
res.push(stack1.top());
stack1.pop();
}
while (res.size()>0)
{
    cout<<res.top().st<<" "<<res.top().et<<'\n';
    res.pop();
}

return 0;
}