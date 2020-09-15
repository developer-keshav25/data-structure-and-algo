#include <iostream>
#include <list>
#include<queue>
using namespace std;
class Graph
	{
	    int V;
	    list<int>*l;
	    public:
	    Graph(int V){
	    this->V = V;
	    l = new list<int>[V];
	    }
	    void addEdge(int x,int y){
	    l[x].push_back(y);
	    l[y].push_back(x);
	    }
	    void printAdjList(){
	        for(int i=0;i<V;i++)
	        {cout<<"Vertex "<<i<<"->";
	            for(int nbr:l[i]){
	                cout<<nbr<<",";
	            }
	        
	            cout<<'\n';
	        }
	    }
        bool check_path(int source,int dest,bool visited[]);
	};
bool Graph::check_path(int source ,int dest,bool visited[]){
    if(source==dest)
    return true;
	visited[source]=true;
    for(int nbr:l[source]){
        if(!visited[nbr]){
            if(check_path(nbr,dest,visited))
            return true;
        }
    }
	return false;
}
int main() {
	int v;
	cin>>v;
	Graph G(v);
	int e;
	cin>>e;
	int s,d,wt;
	for (int i = 1; i <= e; i++) {
    cin>>s>>d>>wt;
    G.addEdge(s,d);
	}
	int source,dest;
	cin>>source>>dest;
	bool*visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	
    if(G.check_path(source,dest,visited))
	cout<<"true";
	else 
    cout<<"false";
	return 0;
}
