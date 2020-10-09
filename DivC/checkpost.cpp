#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fore(i,x,n) for(ll i=x; i<n; i++)
#define fron(i,n) for(ll i=n-1; i>=0;i--)
#define FASTIO std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
std::vector<vector<ll> > vz;
std::vector<ll> temp;
class Graph 
{ 
    ll V;    // No. of vertices 
    list<ll> *adj;    // An array of adjacency lists 
  
    void fillOrder(ll v, bool visited[], stack<ll> &Stack); 
 
    void DFSUtil(ll v, bool visited[]); 
public: 
    Graph(ll V); 
    void addEdge(ll v, ll w); 
    void printSCCs(); 
    Graph getTranspose(); 
}; 
  
Graph::Graph(ll V) 
{ 
    this->V = V; 
    adj = new list<ll>[V]; 
} 
  
  void Graph::DFSUtil(ll v, bool visited[]) 
{ 

    visited[v] = true; 
   // cout << v << " "; 
    temp.push_back(v);
  
    // Recur for all the vertices adjacent to this vertex 
    list<ll>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph Graph::getTranspose() 
{ 
    Graph g(V); 
    for (ll v = 0; v < V; v++) 
    { 
        // Recur for all the vertices adjacent to this vertex 
        list<ll>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            g.adj[*i].push_back(v); 
        } 
    } 
    return g; 
} 
  
void Graph::addEdge(ll v, ll w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::fillOrder(ll v, bool visited[], stack<ll> &Stack) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<ll>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            fillOrder(*i, visited, Stack); 
  
    // All vertices reachable from v are processed by now, push v  
    Stack.push(v); 
} 
  
// The main function that finds and prints all strongly connected  
// components 
void Graph::printSCCs() 
{ 
    stack<ll> Stack; 
  
    // Mark all the vertices as not visited (For first DFS) 
    bool *visited = new bool[V]; 
    for(ll i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Fill vertices in stack according to their finishing times 
    for(ll i = 0; i < V; i++) 
        if(visited[i] == false) 
            fillOrder(i, visited, Stack); 
  
    // Create a reversed graph 
    Graph gr = getTranspose(); 
  
    // Mark all the vertices as not visited (For second DFS) 
    for(ll i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Now process all vertices in order defined by Stack 
    while (Stack.empty() == false) 
    { 
        //Pop a vertex from stack 
        ll v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        { 
            gr.DFSUtil(v, visited); 
            vz.push_back(temp);
            std::vector<ll> vw;
            temp=vw;
            //cout << endl; 
        } 
    } 
} 

int main()
{
	FASTIO
	ll modd=1000000007;
	ll n;
	cin>>n;
	vector<ll> cost(n);
	forn(i,n)
	cin>>cost[i];
	ll m;
	cin>>m;
	Graph gr(n);
	forn(i,m)
	{
		ll u,v;
		cin>>u>>v;
		gr.addEdge(u-1,v-1);
	}
	gr.printSCCs();
	vector<ll> count(vz.size(),0);
	vector<ll> minii(vz.size(),1e9);
	ll sum=0;
	forn(i,vz.size())
	{
		ll mini=1e9+1;
		forn(j,vz[i].size())
		{
			if(mini>cost[vz[i][j]])
				mini=cost[vz[i][j]];
		}
		forn(j,vz[i].size())
		{
			if(mini==cost[vz[i][j]])
				++count[i];
		}
		sum+=mini;
		//cout<<endl;
	}
	cout<<sum<<" ";
	ll prod=1;

	forn(i,vz.size())
	{
		prod*=count[i];
		prod=prod%modd;
	}
	cout<<prod<<endl;
}
