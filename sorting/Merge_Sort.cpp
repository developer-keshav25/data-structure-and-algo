#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
cout<<"Merging these two arrays "<<endl;
int n1 = mid-low+1;
int n2 = high-mid;
int l[n1];
int r[n2];
cout<<"left array -> ";
for (int i = 0; i < n1; i++)
{
    l[i] = arr[low+i];
    cout<<l[i]<<" ";
}
cout<<endl<<"right array -> ";
for (int i = 0; i < n2; i++)
{
    r[i] = arr[mid+1+i];
    cout<<r[i]<<" ";
}
cout<<endl;

int i=0,j=0,k=low;
    while(i<n1&&j<n2){
        if(l[i]<r[j]){
            arr[k] = l[i];
            i+=1;
        }
        else{
            arr[k] = r[j];
            j+=1;
        }
    k++;
    }
    while (i<n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int low,int high){
    if(low<high){
    int mid = (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    }
}
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    cout<<"Sorted Array -> ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}