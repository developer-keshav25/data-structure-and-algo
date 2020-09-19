#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int pivot;
    cin>>pivot;
    int i=0;
    int j = 0;
    while(i<n){
        if(arr[i]>pivot){
            ++i;
        }
        else{
            cout<<"Swapping " <<arr[i] <<" and "<<arr[j]<<endl;
            swap(arr[i],arr[j]);
            ++j;
            ++i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
return 0;
}