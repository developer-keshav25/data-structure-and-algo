#include <iostream>
using namespace std;
int lastindex(int arr[],int idx,int n,int x){
    if(idx ==n)
    return -1;
    if(arr[idx]==x){
    int nidx = lastindex(arr,idx+1,n,x);
    return (idx>nidx)?idx:nidx;
    }
    else    
    return lastindex(arr,idx+1,n,x);
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
    cout<<lastindex(arr,0,n,x);
	return 0;
}
