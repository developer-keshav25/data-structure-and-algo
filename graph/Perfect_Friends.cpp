#include<iostream>
#include<vector>
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
    }
};
void drawTreeComponents(Graph G,int src,bool visited[],vector<int>&comp){
visited[src] = true;
comp.push_back(src);
for(int nbr:G.l[src]){
if(!visited[nbr])
drawTreeComponents(G,nbr,visited,comp);
}
}
int main(){
int V;cin>>V;Graph G(V);
int e;cin>>e;
int x,y;
for (int i = 0; i < e; i++)
{
    cin>>x>>y;
    G.addEdge(x,y);
}
bool visited[V] = {false};
vector<vector<int>>comps;
for (int i = 0; i < V; i++)
{
    if(visited[i]==false){
        vector<int>comp;
        drawTreeComponents(G,i,visited,comp);
        comps.push_back(comp);
    }
}
int pairs = 0;
for (int i = 0; i < comps.size(); i++)
{
    for (int j = i+1; j < comps.size(); j++)
    {
        int count = comps.at(i).size()*comps.at(j).size();
        pairs+=count;
    }
    
}
cout<<pairs;


return 0;
}