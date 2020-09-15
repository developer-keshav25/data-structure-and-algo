#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n1;
    int n2;
    cin>>n1;
    int a1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin>>a1[i];
    }
    cin>>n2;
    int a2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin>>a2[i];
    }
    unordered_map<int,int>map;
    for (int i = 0; i < n1; i++)
    {
        map[a1[i]]+= 1;
    }
    for (int i = 0; i < n2; i++)
    {
        try{
            if(map.at(a2[i])>0){
                cout<<a2[i]<<"\n";
                map[a2[i]]=0;
            }
        }
        catch(const out_of_range &e){
            continue;
        }
    }

return 0;
}