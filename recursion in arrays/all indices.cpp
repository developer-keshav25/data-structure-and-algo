#include <bits/stdc++.h> 
#include <iostream>
#include<queue>
using namespace std;
queue<int> allindex(int arr[],int idx,int n,int x,queue<int>s){
    if(idx ==n)
    return s;
    if(arr[idx]==x)
    s.push(idx);
    return allindex(arr,idx+1,n,x,s);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    queue<int>s;
    s = allindex(arr,0,n,x,s);
    while (!s.empty()) 
    { 
        cout<<s.front()<<'\n'; 
        s.pop(); 
    } 
    cout << '\n'; 
	return 0;
}
