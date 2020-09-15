#include<iostream>
#include<stack>
using namespace std;
int main(){
int n,k;
cin>>n;
int arr[n];
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
cin>>k;
int*nge = new int[n];
stack<int> st;
st.push(n-1);
nge[n-1] = n;
for (int i = n-2; i >=0; i--)
{   while(st.size()>0&&arr[i]>=arr[st.top()])
        st.pop();
    if(st.size()==0)
    nge[i]=n;
    else
    nge[i] = st.top();
    st.push(i);
}
int j;
for (int i = 0; i <=n-k; i++)
{   if(j<i)
    j=i;
    while(nge[j]<i+k){
        j = nge[j];
    }
    cout<<arr[j]<<"\n";
}


return 0;
}