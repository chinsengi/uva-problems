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
#include<unordered_set>
#include<list>
#include<set>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<ctime>
using namespace std;

#define rep(i, s, n) for(int i = s; i < (n); i++)

const int maxn = 22;
const int INF = 1000000000;
int n,m;	
int done[1<<maxn];
int dist[1<<maxn];
char pre[110][25];
char post[110][25];
int t[110];

struct node{
	int d, u;
	bool operator < (const node& nd) const {return d > nd.d;}
};

int main(){
	//freopen("data.out", "w", stdout);
	int kase = 0;
	while(cin>>n>>m&&n){
		rep(i,0,m) {
			cin>>t[i]>>pre[i]>>post[i];
		}
		memset(done,0,sizeof done);
		rep(i,0,1<<n) dist[i] = INF;
		priority_queue<node> q;
		q.push((node){0,(1<<n) - 1});
		dist[(1<<n)-1] = 0;
		while(!q.empty()){
			node nd = q.top(); q.pop();
			int u = nd.u;
			if(done[u]) continue;
			done[u]=1;
			rep(i,0,m){
				bool ok = true;
				rep(j,0,n){
					if(pre[i][j]=='0')continue;
					else if(pre[i][j]=='+') {ok = u&(1<<(j)); if(ok == false)break;}
					else if(pre[i][j]=='-') {ok = !(u&(1<<j)); if(ok == false)break;}
				}
				if(ok) {
					int b = u;
					rep(j,0,n){
						if(post[i][j]=='0')continue;
						else if(post[i][j]=='-') b = b & ~(1<<j);
						else b = b|(1<<j);
					} 
					if(dist[b]>dist[u]+t[i]){
						dist[b]= dist[u]+t[i];
						q.push((node){dist[b],b});
					}
				}
			}
		}
		printf("Product %d\n", ++kase);
		if(dist[0] == INF) printf("Bugs cannot be fixed.\n\n");
		else printf("Fastest sequence takes %d seconds.\n\n", dist[0]);
	}
}

