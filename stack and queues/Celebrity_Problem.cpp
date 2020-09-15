#include<iostream>
#include<stack>
using namespace std;
void celebrity(int**arr,int n){
stack<int>st;
for (int i = 0; i < n; i++)
{
    st.push(i);
}
while(st.size()>=2){
    int i = st.top();
    st.pop();
    int j = st.top();
    st.pop();
    if(arr[i][j]==1)
    st.push(j);
    else
    st.push(i);
}
int x = st.top();
for (int i = 0; i < n; i++)
{
    if(i!=x){
    if(arr[x][i]==1||arr[i][x]==0){
        cout<<"none";
        return;
    }
    }

}
cout<<x;
}
int main(){
    int n;
    cin>>n;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
    arr[i] = new int[n];
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>ch;
            arr[i][j]=ch-'0';
        }
        
    }
    celebrity(arr,n);
return 0;
}