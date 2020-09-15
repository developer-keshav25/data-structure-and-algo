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
        void Multisolver(int source,int dest,bool visited[],int criteria,int k,string psf,int wsf);
	};

string spath;
int spathwt = INT_MAX;
string lpath;
int lpathwt = INT_MIN;
string cpath;
int cpathwt = INT_MAX;
string fpath;
int fpathwt = INT_MIN;
typedef pair<string, int> pd; 
struct comp{
    bool operator()(pair<string,int>a,pair<string,int>b){
        return a.second>b.second;
    }
};
priority_queue<pd,vector<pd>,comp>priority;
void Graph::Multisolver(int source ,int dest,bool visited[],int criteria,int k,string psf,int wsf){
    if(source==dest){
    if(wsf<spathwt){
    spathwt = wsf;
    spath = psf;
    }
    
    if(wsf>lpathwt){
    lpathwt = wsf;
    lpath = psf;
        
    }
    if(wsf>criteria&&wsf<cpathwt){
    cpathwt = wsf;
    cpath = psf;
    }
    
    if(wsf<criteria&&wsf>fpathwt){
    fpathwt = wsf;
    fpath = psf;
    }
    
    if(priority.size()<k)
    priority.push(make_pair(psf,wsf));
    else{
        if(priority.top().second<wsf){
        priority.pop();
        priority.push(make_pair(psf,wsf));}
    }
    return;}
	visited[source]=true;
    for(auto nbr:l[source]){
        if(!visited[nbr.first]){
            Multisolver(nbr.first,dest,visited,criteria,k,psf+to_string(nbr.first),wsf+nbr.second);
        }
    }
	visited[source] =false;
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
	int source,dest;
	cin>>source>>dest;
	bool*visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
    int criteria,k;
    cin>>criteria>>k;
    G.Multisolver(source,dest,visited,criteria,k,std::to_string(source),0);
	cout<<"Smallest Path = " + spath + "@" + to_string(spathwt)<<endl;
    cout<<"Largest Path = " + lpath + "@" + to_string(lpathwt)<<endl;
    cout<<"Just Larger Path than " + to_string(criteria) + " = " + cpath + "@" + to_string(cpathwt)<<endl;
    cout<<"Just Smaller Path than " + to_string(criteria) + " = " + fpath + "@" + to_string(fpathwt)<<endl;
    cout<<to_string(k) + "th largest path = " + priority.top().first + "@" + to_string(priority.top().second)<<endl;
	return 0;
}
