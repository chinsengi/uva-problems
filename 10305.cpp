#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 100 +10;
int c[maxn];
int topo[maxn], t;
int m,n;
int G[maxn][maxn];
bool dfs(int u){
	c[u] = -1;
	for(int v = 0; v< n; v++){
		if(G[u][v]){
			if(c[v] < 0) return false;
			else if(!c[v] && !dfs(v)) return false;
		}
	}
	c[u] = 1; topo[--t] = u;
	return true;
}

bool toposort(){
	t = n;
	memset(c, 0, sizeof(c));
	for(int u = 0; u < n; u++){
		if(!c[u]){
			if(!dfs(u)) return false;
		}
	}
	return true;
}

int main()
{
	while(scanf("%d %d", &n, &m)&&n){//m might be 0
		memset(G,0, sizeof(G));
		int u, v;
		for(int i = 0; i < m; i++){
			scanf("%d %d", &u, &v);
			G[u-1][v-1] = 1;
		}
		if(toposort()){
			for(int i = 0; i < n-1; i++){
				printf("%d ", topo[i]+1);
			}
			printf("%d\n", topo[n-1]+1);
		}
	}
}