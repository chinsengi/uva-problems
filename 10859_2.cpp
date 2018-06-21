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
const int M = 2000;
const int maxn = 1005;	
int t, n,m;
vector<int> roads[maxn];
int vis2[maxn];
int dfs(int junc, int f, int fa){
	vis2[junc] = 1;
	//junc doesnt have light
	int x = 0;
	if(f){
		for(auto r: roads[junc])if(r!=fa){
			x += dfs(r,0,junc);
		}
		if(fa!=-1) x++;
	}
	//junc has light;
	int y = 0;
	for(auto r: roads[junc])if(r!= fa){
		y += dfs(r,1, junc);
	}
	y+=M;
	if(!f&&fa!=-1)y++;
	if(f&&x>y) return y; 
	else if(f&&x<=y) return x;
	else return y;
	
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		rep(i,0,n) roads[i].clear();
		rep(i,0,m) {
			int a,b;
			cin>>a>>b;
			roads[a].push_back(b);
			roads[b].push_back(a);
		}
		memset(vis2,0,sizeof vis2);
		int p = 0, q = 0;
		rep(i,0,n) if(!vis2[i]){
			int ans = dfs(i, 1, -1);
			p += ans/M;
			q += ans%M;
		}
		cout<<p<<" "<<m-q<<" "<<q<<endl;
	}
}