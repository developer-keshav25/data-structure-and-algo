#include <iostream>
using namespace std;
int maxarr(int arr[],int idx,int n){
    if(idx==n-1){
    return arr[idx];}
    int a = arr[idx];
    int b = maxarr(arr,idx+1,n);
    int max = (a>b)?a:b;
    return max;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<maxarr(arr,0,n);
	return 0;
}
