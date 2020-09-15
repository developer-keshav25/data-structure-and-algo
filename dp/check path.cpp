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
    	bool check_path(int source,int dest,int v){
        if(source==dest)
        return true;
        bool* visited = new bool[v]; 
	    for (int i = 0; i < v; i++)
	        visited[i] = false;
        visited[source]=true;
        list<int>queue;
        queue.push_back(source);
        while(!queue.empty()){
        int s = queue.front();
        queue.pop_front();
        for(int nbr:l[s]){
        if(nbr==dest)
        return true;
        if(!visited[nbr]){
            queue.push_back(nbr);
            visited[nbr]=true;
        }
            }
        }
        return false;
    	}
	};

int main() {
	int v;
	cin>>v;
	Graph G(v);
	int e;
	cin>>e;
	int s,d,wt;
	for (int i = 0; i < e; i++) {
    cin>>s>>d>>wt;
    G.addEdge(s,d);
	}
// 	G.printAdjList();
	int source,dest;
	cin>>source>>dest;
	if(G.check_path(source,dest,v))
	cout<<"true";
	else
	cout<<"false";
	return 0;
}
