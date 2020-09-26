#include<iostream>
using namespace std;
void sort01(int arr[],int n){
    int pivot = 0;
    int i=0,j=0;
    while(i<n){
        if(arr[i]==pivot){
        cout<<"Swapping index "<<i<<" and index "<<j<<endl;
        swap(arr[i],arr[j]);
        ++j;
        }
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
    sort01(arr,n);
    for(int x:arr){
        cout<<x<<endl;
    }
    
return 0;
}