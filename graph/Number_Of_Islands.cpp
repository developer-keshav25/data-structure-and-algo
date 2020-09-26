#include<iostream>
using namespace std;
void drawtreeforComponent(int **arr,int i,int j,bool**visited,int n,int m){
    if(i<0||j<0||i>=n||j>=m||arr[i][j]==1||visited[i][j]==true)
    return;
    visited[i][j]  = true;
    drawtreeforComponent(arr,i-1,j,visited,n,m);
    drawtreeforComponent(arr,i,j+1,visited,n,m);
    drawtreeforComponent(arr,i,j-1,visited,n,m);
    drawtreeforComponent(arr,i+1,j,visited,n,m);
}
int main(){
    int n;cin>>n;
    int m;cin>>m;
    int **arr = new int*[n];
    bool **visited = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        visited[i] = new bool[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            cin>>arr[i][j];
        }
        
    }
    int count =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]==0 &&visited[i][j]==false){
                drawtreeforComponent(arr,i,j,visited,n,m);
                count++;
            }
        }
        
    }
    cout<<count;
    
return 0;
}