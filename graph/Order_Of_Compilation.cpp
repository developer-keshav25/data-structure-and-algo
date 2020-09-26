//Directed Acyclic Graph
// topological sorting
#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;
class Graph
{
public:
    int V;
    vector<int> *l;
    Graph(int V)
    {
        this->V = V;
        l = new vector<int>[V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }
};
void TopologicalSort(Graph G,int src,bool visited[],stack<int>&comp){
    visited[src] = true;
    for (int nbr:G.l[src])
    {
        if(!visited[nbr]){
            TopologicalSort(G,nbr,visited,comp);
        }
    }
    comp.push(src);
}

int main()
{
    int V;
    cin >> V;
    Graph G(V);
    int e;
    cin >> e;
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        G.addEdge(x, y);
    }
    bool visited[V];
    fill(visited,visited+V,false);
    stack<int>st;
    for (int v = 0; v < V; v++)
    {
        if(!visited[v]){
            TopologicalSort(G,v,visited,st);
        }
    }
    while (st.size()>0)
    {
            cout<<st.top()<<endl;
            st.pop();
    }
    
    return 0;
}