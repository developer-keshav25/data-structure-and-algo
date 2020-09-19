#include<iostream>
using namespace std;
int partition(int arr[],int lo,int hi){
    int i=lo;
    int j = lo;
    int pivot = arr[hi];
    cout<<"pivot -> "<<pivot<<endl;
    while(i<=hi){
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
     cout<<"pivot index -> " <<(j - 1)<<endl;
    return j-1;
}
void quicksort(int arr[],int lo,int hi){
    if(lo>hi)
    return;
    int pindex = partition(arr,lo,hi);
    quicksort(arr,lo,pindex-1);
    quicksort(arr,pindex+1,hi);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}