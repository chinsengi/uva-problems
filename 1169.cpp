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
const int INF = 1000000000;
int t;
int c, n;
int d[100005];

struct pac{
	int x,y,w;
	pac(int x, int y, int w): x(x), y(y), w(w){}
};

vector<pac> packages;

int dist(int x1, int y1, int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}


int dp(int start){
	if(d[start]!=-1) return d[start];
	if(start == n) return d[start] = 0;
	int ans = INF;
	int i = start;
	int wei = packages[i].w;
	while(wei<=c&&i<n){
		int tmp = dist(0,0,packages[start].x, packages[start].y);
		for(int j = start+1; j <= i; j++){
			int x1 = packages[j-1].x;
			int y1 = packages[j-1].y;
			int x2 = packages[j].x;
			int y2 = packages[j].y;
			tmp += dist(x1,y1,x2,y2);
		}
		tmp += dist(0,0,packages[i].x, packages[i].y);
		ans = min(tmp + dp(i+1), ans);
		i++; wei+=packages[i].w;
	}
	return d[start] = ans;
}

int main(){
	cin>>t;
	while(t--){
		cin>>c>>n;
		packages.clear();
		rep(i,0,n){
			int x,y,w;
			cin>>x>>y>>w;
			packages.push_back(pac(x,y,w));
		}
		memset(d,-1,sizeof d);
		cout<<dp(0)<<endl;
		if(t) cout<<endl;
	}
}