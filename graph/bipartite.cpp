#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Pair{
    int v;
    string psf;
    int lvl;
    Pair(int v,string psf,int lvl){
        this->v = v;
        this->psf = psf;
        this->lvl = lvl;
    }
};
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
        l[y].push_back(x);
    }
};
bool isbipartite(Graph G, int src, int visited[])
{
    queue<Pair>queue;
    queue.push(Pair(src,to_string(src),0));
    while (queue.size() > 0)
    {
        Pair p = queue.front();
        queue.pop();
        if (visited[p.v]!=-1){//we have found the cycle
            if(p.lvl!=visited[p.v])
            return false;
        } 
        visited[p.v] = p.lvl;
        for (int nbr : G.l[p.v])
        {
            if (visited[nbr]==-1)
            {
                queue.push(Pair(nbr,p.psf+to_string(nbr),p.lvl+1));
            }
        }
    }
    return true;
}
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
        G.addEdge(x, y);
    }
    int visited[V];
    fill(visited,visited+V,-1);
    for (int v = 0; v < V; v++)
    {
        if (visited[v]==-1)
            if (!isbipartite(G, v, visited)){
                cout << "false";
                return 0;
            }
    }
    cout<<"true";
    return 0;
}