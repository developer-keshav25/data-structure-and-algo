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
int quickselect(int arr[],int lo,int hi,int x){
int pi = partition(arr,lo,hi);
if(x<pi){
    return quickselect(arr,lo,pi-1,x);
}
else if(x>pi){
    return quickselect(arr,pi+1,hi,x);
}
else
return arr[x];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<quickselect(arr,0,n-1,x-1);
return 0;
}