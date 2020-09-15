#include<iostream>
#include<stack>
using namespace std;
int main(){
string input;
getline(cin,input);
stack<int>st;
int i =1;
for(char ch:input){
    if(ch=='d'){
        st.push(i);
        ++i;
    }
    else{
        st.push(i);
        ++i;
        while (st.size()>0)
        {
            cout<<st.top();
            st.pop();
        }
    }
}
st.push(i);
while (st.size()>0)
{
    cout<<st.top();
    st.pop();
}

return 0;
}