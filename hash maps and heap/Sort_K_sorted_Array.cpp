#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    priority_queue<int, vector<int>, greater<int>>q;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];

    }
    int k;cin>>k;
    for (int i = 0; i <= k; i++)
    {
        q.push(a[i]);
    }
    for (int i = k+1; i < n; i++)
    {
        cout<<q.top()<<'\n';
        q.pop();
        q.push(a[i]);
    }
    while (q.size()>0)
    {
        cout<<q.top()<<'\n';
        q.pop();
    }
    
    
    
return 0;
}