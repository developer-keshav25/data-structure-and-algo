#include<iostream>
#include<queue>
using namespace std;
int main(){
priority_queue<int, vector<int>, greater<int>>q;
int n;cin>>n;
int a[n];
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}
int k;cin>>k;
for (int i = 0; i < k; i++)
{
    q.push(a[i]);
}
for (int i = k; i < n; i++)
{
    if(q.top()<a[i]){
        q.pop();
        q.push(a[i]);
    }
}
while (q.size()>0)
{
 cout<<q.top()<<'\n';
 q.pop();
}

return 0;
}