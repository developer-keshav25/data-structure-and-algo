#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
unordered_map<char,int>freq;
string s;
cin>>s;
for(char ch:s){
freq[ch]+=1;
}
int max = 0;
char cmax;
for(auto itr=freq.begin();itr!=freq.end();itr++){
    if(itr->second>max){
    max = itr->second;
    cmax = itr->first;
    }
}
cout<<cmax;
return 0;
}