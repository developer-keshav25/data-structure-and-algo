//Prims algorithm for minimum spanning tree
#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;

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
    int src;
    cin>>src;
    bool visited[V];
    fill(visited,visited+V,false);
    stack<pair<int,string>>st;
    st.push(make_pair(src,to_string(src)));
    while (st.size() > 0)
    {
        pair<int,string> rem = st.top();
        st.pop();
        if (visited[rem.first]){//already infected
            continue;
        } 
        visited[rem.first] = true;
        cout<<rem.first<<"@"<<rem.second<<endl;
        for (pair<int,int> nbr : G.l[rem.first])
        {
            if (!visited[nbr.first])
            {
                st.push(make_pair(nbr.first,rem.second+to_string(nbr.first)));
            }
        }
    }
    return 0;
}