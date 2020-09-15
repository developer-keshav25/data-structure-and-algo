#include<iostream>
#include<list>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    stack<int>stack;
    int nge[n];
    nge[n-1] = -1;
    stack.push(arr[n-1]);
    for (int i = n-2; i >=0; --i)
    {
        while (stack.size()>0 && arr[i]>=stack.top())
        {
            stack.pop();
        }
        if(stack.empty())
        nge[i] = -1;
        else
        nge[i]=stack.top();
        
        stack.push(arr[i]);
    }
    // cout<<nge[4];
    for (int i = 0; i < n; i++)
    {
        cout<<nge[i]<<'\n';
    }
    return 0;
}