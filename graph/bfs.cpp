#include<iostream>
#include<vector>
#include<queue>
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

int main(){
int V;cin>>V;Graph G(V);
int e;cin>>e;
int x,y,wt;
for (int i = 0; i < e; i++)
{
    cin>>x>>y>>wt;
    G.addEdge(x,y);
}
int src;
cin>>src;
bool visited[V] = {false};
queue<pair<int,string>>queue;
queue.push(make_pair(src,to_string(src)));
while (queue.size()>0)
{
    pair<int,string>p = queue.front();
    queue.pop();
    if(visited[p.first])
    continue;
    visited[p.first] = true;
    cout<<p.first<<"@"<<p.second<<endl;
    for(int nbr:G.l[p.first])
    {
        if(!visited[nbr]){
            queue.push(make_pair(nbr,p.second+to_string(nbr)));
        }
    }
    
}

return 0;
}