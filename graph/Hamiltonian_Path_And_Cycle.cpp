#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Graph{
    public:
    int V;
    vector<int>*l;
    Graph(int V){
        this->V =V;
        l = new vector<int>[V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
};
void checkHamiltonian(Graph G,int src,unordered_set<int> visited,string psf,int osrc){
    if(visited.size()==G.V-1){
        cout<<psf;
        bool closingEdge = false;
        for(int x:G.l[src]){
            if(x==osrc){
            closingEdge = true;
            break;
            }
        }
        if(closingEdge)
        cout<<"*"<<endl;
        else
        cout<<"."<<endl;
        return;
    }
    
    visited.insert(src);
    for(int nbr:G.l[src]){
        if(visited.find(nbr)==visited.end()){
            checkHamiltonian(G,nbr,visited,psf+to_string(nbr),osrc);
        }
    }
    visited.erase(src);

}

int main(){
int V;cin>>V;Graph G(V);
int e;cin>>e;
int x,y,src,wt;
for (int i = 0; i < e; i++)
{
    cin>>x>>y>>wt;
    G.addEdge(x,y);
}
cin>>src;
unordered_set<int>visited;
checkHamiltonian(G,src,visited,""+to_string(src),src);

return 0;
}