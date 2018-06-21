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
//1<<16 = 2^16
typedef long long  ll;
typedef pair<int, int>  ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const ll n = 1e10;
int vis[n+10];


int main(){
	int m = sqrt(n+0.5);
	memset(vis,0, sizeof vis);
	for(int i = 2; i <= m; i++)if(!vis[i]){
		for(int j = i*i; j <= n; j+= i) vis[j] = 1;
	}
	ll ans;
	for(int i = 1; i < 1e10+1; i++) if(!vis[i])ans++;
	cout<<ans;
}