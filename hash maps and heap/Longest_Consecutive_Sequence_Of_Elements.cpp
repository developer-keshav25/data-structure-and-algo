#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    unordered_map<int,bool>map;
    for (int i = 0; i < n; i++)
    {
        map[a[i]] = true;
    }
  for (int val:a)
  {
      if(map.find(val-1)!=map.end())
      map[val]=false;
  }
  
    int msp = 0;
    int ml  = 0;
    for(int val:a){
        if(map.at(val)==true){
            int tl =1;
            int tsp = val;
            while(map.find(tl+tsp)!=map.end()){
                tl++;
            }
            
            if(tl>ml){
            ml = tl;
            msp = tsp; 
            }
        }
    }
    for (int i = 0; i < ml; i++)
    {
        cout<<msp+i<<"\n";
    }
    
    
    
return 0;
}