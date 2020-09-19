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
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int  j = i+1; j< n; j++)
        {   cout<<"Comparing "<<arr[j]<<" and "<<arr[min]<<'\n';
            if(arr[j]<arr[min])
            min  =j;
        }
        cout<<"Swapping "<<arr[i]<<" and "<<arr[min]<<'\n';
        swap(arr[i],arr[min]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\n";
    }
    
return 0;
}