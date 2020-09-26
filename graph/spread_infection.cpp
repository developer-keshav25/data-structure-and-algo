#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Pair{
    int v;
    int time;
    Pair(int v,int time){
        this->v = v;
        this->time = time;
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
    int src,t;
    cin>>src>>t;
    int visited[V];
    fill(visited,visited+V,0);
    queue<Pair>queue;
    queue.push(Pair(src,1));
    int count = 0;
    while (queue.size() > 0)
    {
        Pair p = queue.front();
        queue.pop();
        if (visited[p.v]>0){//already infected
            continue;
        } 
        visited[p.v] = p.time;
        if(p.time>t)
        break;
        ++count;
        for (int nbr : G.l[p.v])
        {
            if (visited[nbr]==0)
            {
                queue.push(Pair(nbr,p.time+1));
            }
        }
    }
    cout<<count;
    return 0;
}