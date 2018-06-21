#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<sstream>
#include<utility>
#include<deque>
#include<list>
#include<set>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<ctime>
using namespace std;

#define rep(i, s, n) for(int i = s; i < n; i++)
const int maxn = 200;
int n,m;	
int p[maxn];
struct edge{
	int f,s;
	int w;
	edge(int f = 0, int s = 0, int w = 0): f(f), s(s), w(w){}
};
vector<edge> edges;

int find(int x){return p[x]==x ? x : p[x] = find(p[x]);}

int kruskal(int start){
	int ec = 0;
	int minw = 20000, maxw = 0;
	rep(i, start, m){
		int px = find(edges[i].f);
		int py = find(edges[i].s);
		if(px != py) {
			ec++;
			minw = min(minw, edges[i].w);
			maxw = max(maxw, edges[i].w);
			p[px] = py;
		}
	}
	if(ec!=n-1)return 20000;
	else return maxw-minw;
}


int main(){
//	freopen("data.out", "w", stdout);
	while(cin>>n>>m&&n){
		edges.clear();
		rep(i,0,m){
			int f,s,w;
			cin>>f>>s>>w;
			edges.push_back((edge){f,s,w});
		}
		sort(edges.begin(), edges.end(), [](const edge& e1, const edge& e2){return e1.w < e2.w;});
		rep(i,1,n+1) p[i] = i;
		int ans = kruskal(0);
		if(ans == 20000) cout<<-1<<endl;
		else{
			rep(i,0,m-n+2){
				rep(i,1,n+1) p[i] = i;
				ans = min(kruskal(i),ans);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}









