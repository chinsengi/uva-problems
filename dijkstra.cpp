#include<cstdio>
#include<cstring>
using namespace std;

int const INF = 1<<30;
struct Edge{
	int from, to ,dist;
	Edge(int u, int v, int d) : from(u), to(v), dist(d){}
};

struct Dijkstra{
	int n,m; 
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
	
	void init(int n){
		this->n = n;
		for(int i = 0; i < n; i++){
			G[i].clear();
		}
		edges.clear();
	}
	
	void AddEdge(int from, int to, int dist){
		edges.push_back(Edge(from, to,dist));
		m = edges.size();
		G[from].push_back(m-1);
	}
	
	
	void dijkstra(int s){
		
	}
}