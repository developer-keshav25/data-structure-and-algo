// this has been done according to pepcoding solution to match output
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
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int key = arr[i]; 
        while (j>=0)
        { cout<<"Comparing "<<arr[j+1]<<" and "<<arr[j]<<endl;
            if(arr[j]>arr[j+1]){
            cout<<"Swapping "<<arr[j]<<" and "<<arr[j+1]<<endl;
            swap(arr[j],arr[j+1]);
            j-=1;
            }
            else
            break;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    
return 0;
}