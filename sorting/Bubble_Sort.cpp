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
        for (int j = 0; j < n-i-1; j++)
        {
            cout<<"Comparing "<<arr[j+1]<<" and "<<arr[j]<<'\n';
            if(arr[j]>arr[j+1]){
            cout<<"Swapping "<<arr[j+1]<<" and "<<arr[j]<<'\n';
            swap(arr[j],arr[j+1]);
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    
return 0;
}