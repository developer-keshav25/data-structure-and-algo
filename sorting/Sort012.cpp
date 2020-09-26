#include<iostream>
using namespace std;
void sort012(int arr[],int n){
    int i=0,j=0,k=n-1;
    while(i<=k){
        if(arr[i]==0){
        cout<<"Swapping index "<<i<<" and index "<<j<<endl;
        swap(arr[i],arr[j]);
        ++j;
        ++i;
        }
        else if(arr[i]==2){
            cout<<"Swapping index "<<i<<" and index "<<k<<endl;
            swap(arr[i],arr[k]);
            --k;
        }
        else
        ++i;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort012(arr,n);
    for(int x:arr){
        cout<<x<<endl;
    }
    
return 0;
}