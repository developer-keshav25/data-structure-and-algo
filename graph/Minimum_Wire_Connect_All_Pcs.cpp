//Prims algorithm for minimum spanning tree
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Pair{
    int v;
    int av;
    int wsf;
    Pair(int v,int av,int wsf){
        this->v = v;
        this->av = av;
        this->wsf = wsf;
    }
    bool operator<(Pair o)const
    {
        return this->wsf>o.wsf;
    }
};

class Graph
{
public:
    int V;
    vector<pair<int,int>> *l;
    Graph(int V)
    {
        this->V = V;
        l = new vector<pair<int,int>>[V];
    }
    void addEdge(int x, int y,int z)
    {
        l[x].push_back(make_pair(y,z));
        l[y].push_back(make_pair(x,z));
    }
};

int main()
{
    int V;
    cin >> V;
    Graph G(V);
    int e;
    cin >> e;
    int x, y, wt;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> wt;
        G.addEdge(x, y,wt);
    }
    bool visited[V];
    fill(visited,visited+V,false);
    priority_queue<Pair>pq;
    pq.push(Pair(0,-1,0));
    while (pq.size() > 0)
    {
        Pair p = pq.top();
        pq.pop();
        if (visited[p.v]){//already infected
            continue;
        } 
        visited[p.v] = true;
        if(p.av!=-1)
        cout<<'['<<p.v<<"-"<<p.av<<"@"<<p.wsf<<']'<<endl;
        for (pair<int,int> nbr : G.l[p.v])
        {
            if (!visited[nbr.first])
            {
                pq.push(Pair(nbr.first,p.v,nbr.second));
            }
        }
    }
    return 0;
}