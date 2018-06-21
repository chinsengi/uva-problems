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
int d[maxn][maxn];
string p[maxn];
int vis[maxn];
map<string, int> people;
int n,m;

int main(){

	int kase = 0;
	cin>>n>>m;
	for(;;){
		people.clear();
		memset(vis,0,sizeof vis);
		memset(d,0,sizeof d);
		int np = 0;
		rep(i,0,m){
			string a,b;
			cin>>a>>b;
			if(!people.count(a)) {people[a] = np; p[np++] = a;}
			if(!people.count(b)) {people[b] = np; p[np++] = b;}
			d[people[a]][people[b]] = 1;
		}
		rep(k,0,n) rep(i,0,n) rep(j,0,n){
			d[i][j] = d[i][j] || (d[i][k]&&d[k][j]);
		}
		cout<<"Calling circles for data set "<<++kase<<":"<<endl;
		rep(i,0,n){
			if(!vis[i]){
				cout<<p[i];vis[i] = 1;
				rep(j,0,n) if(d[i][j]&&d[j][i]&&!vis[j]){
					cout<<", "<<p[j];
					vis[j] = 1;
				}
				cout<<endl;
			}
		}
		if(cin>>n>>m&&n)cout<<endl;
		else break;
	}
}