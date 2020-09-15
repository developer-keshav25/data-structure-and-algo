#include<iostream>
#include<stack>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
int lb[n];    //index smallest element on left 
int rb[n];    //index of smallest element on right
stack<int>st;
st.push(n-1);
rb[n-1] = n;
for (int i = n-2; i >=0; i--)
{
    while(st.size()>0&&arr[i]<=arr[st.top()])
    st.pop();
    if(st.size()==0)
    rb[i]=n;
    else
    rb[i] = st.top();
    st.push(i);
}
stack<int> st1;
st1.push(0);
lb[0] = -1;
for (int i = 1; i <n; i++)
{
    while(st1.size()>0&&arr[i]<=arr[st1.top()])
    st1.pop();
    if(st1.size()==0)
    lb[i]=-1;
    else
    lb[i] = st1.top();
    st1.push(i);
}
int max=0;
for (int i = 0; i < n; i++)
{
    int width = rb[i]-lb[i]-1;
    int area = arr[i]*width;
    if(area>max)
    max = area;
}
cout<<max;

return 0;
}