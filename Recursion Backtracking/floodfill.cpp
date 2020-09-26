#include<iostream>
using namespace std;
void floodfill(int **flood,int n,int m,int i,int j,string ans,bool **visited){
    if(i<0||j<00||i==n||j==m||flood[i][j]==1||visited[i][j]==true)
    return;
    if(i==n-1&&j==m-1){
    cout<<ans<<endl;
    return;
    }
    visited[i][j] = true;
    floodfill(flood,n,m,i-1,j,ans+"t",visited);
    floodfill(flood,n,m,i,j-1,ans+"l",visited);
    floodfill(flood,n,m,i+1,j,ans+"d",visited);
    floodfill(flood,n,m,i,j+1,ans+"r",visited);
    visited[i][j] = false;
}
int main(){
    int n;cin>>n;
    int m;cin>>m;
    int **flood = new int*[n];
    bool **visited = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        flood[i] = new int[m];
        visited[i] = new bool[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>flood[i][j];
            visited[i][j] = false;
        }
        
    }
    
    floodfill(flood,n,m,0,0,"",visited);
return 0;
}