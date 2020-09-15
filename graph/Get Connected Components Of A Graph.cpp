#include <bits/stdc++.h> 
#include <iostream>
#include <list>
#include<queue>
using namespace std;
class Graph
	{
	    int V;
	    list<pair<int,int>>*l;
	    public:
	    Graph(int V){
	    this->V = V;
	    l = new list<pair<int,int>>[V];
	    }
	    void addEdge(int x,int y,int z){
	    l[x].push_back(make_pair(y,z));
	    l[y].push_back(make_pair(x,z));
	    }
	    void printAdjList(){
	        for(int i=0;i<V;i++)
	        {cout<<"Vertex "<<i<<"->";
	            for(auto nbr:l[i]){
	                cout<<nbr.first<<" "<<nbr.second<<",";
	            }
	        
	            cout<<'\n';
	        }
	    }
        void isconnected(int source,bool visited[],list<int>&connections);
	};
void Graph::isconnected(int source ,bool visited[],list<int>&connections){
    connections.push_back(source);
    visited[source] =true;
        
        for(auto nbr:l[source]){
        if(!visited[nbr.first])
        isconnected(nbr.first,visited,connections);
        }
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
    G.addEdge(s,d,wt);
	}
	bool*visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
    list<list<int>>comp;
    for (int i = 0; i < v; i++){
        if(!visited[i]){
        list<int>connections;
        G.isconnected(i,visited,connections);
        comp.push_back(connections);
        }
    }
    list<list<int> >::iterator itr; 
  
    cout<<"[";
    for (itr = comp.begin(); itr != comp.end(); ++itr) { 
  
        cout << "["; 
        list<int>::iterator itr1; 
        list<int>& single_list_pointer = *itr; 
  
        for (itr1 = single_list_pointer.begin(); itr1 != --single_list_pointer.end(); itr1++) { 
            cout<< *itr1 << ","; 
        }
        cout<<*itr1;
     
    cout << "]"; 
}
  cout<<"]";
    
	return 0;
}
