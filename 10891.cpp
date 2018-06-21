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
int seq[105];
int cusum[105];
int d[105][105];

inline int sum(int a, int b){
	return cusum[b] - cusum[a-1];
}

int dp(int a, int b){
	if(d[a][b] != -INF) return d[a][b];
	int ans = -INF;
	if(a>b) return 0;
	if(a==b) {d[a][b] = seq[a]; return seq[a];}
	else{
		rep(i,a,b+1) ans = max(ans, sum(a,i)-dp(i+1,b));
		for(int i = b; i >= a; i--) ans = max(ans, sum(i,b)-dp(a,i-1));
	}
	d[a][b] = ans;
	return ans;
}


int main(){
	int n;
	while(cin>>n&&n){
		cusum[0] = 0;
		rep(i,1,n+1){
			cin>>seq[i];
			cusum[i] = cusum[i-1] + seq[i];
		}
		rep(i,1,n+1) rep(j,1,n+1) d[i][j] = -INF;
		int ans;
		ans  = dp(1,n);
		cout<<ans<<endl;
	}
}