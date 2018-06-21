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
const int INF = 10000;
const int maxn = 110;
int c,s,q;
int g[maxn][maxn];

	
	
int main(){
	cin>>c>>s>>q;
	int kase = 0;
	for(;;){
		rep(i,0,c+1) rep(j,0,c+1) g[i][j] = INF;
		rep(i,0,s){
			int c1,c2,d;
			cin>>c1>>c2>>d;
			g[c1][c2] = d;
			g[c2][c1] = d;
		}
		rep(k,1,c+1) rep(i,1,c+1) rep(j,1,c+1) g[i][j] = g[j][i] = min(g[i][j], max(g[i][k],g[k][j]));
		cout<<"Case #"<<++kase<<endl;
		rep(i,0,q){
			int c1,c2;
			cin>>c1>>c2;
			if(g[c1][c2] == INF) cout<<"no path"<<endl;
			else cout<<g[c1][c2]<<endl;
		}
		if(cin>>c>>s>>q&&c) cout<<endl;
		else break;
	}
}