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
const int maxn = 250*250+5;
const int INF = 1000000000;
int n,p,q;
int vis[maxn];
vector<int> lis;
int g[maxn];
int d[maxn];

int main(){
	int t;
	cin>>t;
	int kase = 0;
	while(t--){
		cin>>n>>p>>q;
		memset(vis,0,sizeof vis);
		rep(i,1,p+2) {int a;cin>>a;vis[a] = i;}
		lis.clear();
		rep(i,1,q+2) {
			int b; cin>>b;
			if(vis[b]) lis.push_back(vis[b]);
		}
		int longer = max(p+1,q+1);
		rep(i,1, lis.size()+1) g[i] = INF;
		rep(i,0,lis.size()){
			int k = lower_bound(g+1, g+longer+1, lis[i])-g;
			d[i] = k;
			g[k] = lis[i];
		}
		int ans  = d[lis.size()-1];
		cout<<"Case "<<++kase<<": "<<ans<<endl;
	}
}