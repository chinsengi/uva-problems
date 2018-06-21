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

const int maxn = 40;
const int INF = 100;
vector<int> g[maxn];
string p[maxn];
map<string, int> people;
int n,m;
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> s;

void dfs(int u){
	pre[u] = lowlink[u] = ++dfs_clock;
	s.push(u);
	rep(i,0, g[u].size()){
		int v = g[u][i];
		if(!pre[v]){
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}else if(!sccno[v]){
			lowlink[u] = min(pre[v], lowlink[u]);
		}
	}
	
	if(lowlink[u]==pre[u]){
		scc_cnt++;
		for(;;){
			int x = s.top(); s.pop();
			sccno[x] = scc_cnt;
			cout<<p[x];
			if(x==u) {cout<<endl;break;}
			else cout<<", ";
		}
	}
}


int main(){
	int kase = 0;
	cin>>n>>m;
	for(;;){
		people.clear();
		rep(i,0,n) g[i].clear();
		int np = 0;
		rep(i,0,m){
			string a,b;
			cin>>a>>b;
			if(!people.count(a)) {people[a] = np; p[np++] = a;}
			if(!people.count(b)) {people[b] = np; p[np++] = b;}
			g[people[a]].push_back(people[b]);
		}
		cout<<"Calling circles for data set "<<++kase<<":"<<endl;
		memset(pre,0,sizeof pre);
		memset(sccno, 0, sizeof sccno);
		dfs_clock = scc_cnt = 0;
		rep(i,0,n) if(!pre[i]) dfs(i);
		if(cin>>n>>m&&n)cout<<endl;
		else break;
	}
}