#include <iostream>
using namespace std;
void printarr(int arr[],int idx,int n){
    if(idx==n)
    return ;
    cout<<arr[idx]<<'\n';
    printarr(arr,++idx,n);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    printarr(arr,0,n);
	return 0;
}
