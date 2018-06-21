#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 40005;
const ll p = 1000000007;
int n,m;
vector<int> graph[maxn];
ll fac[maxn];
ll s[maxn];
int vis[maxn];

void gcd(ll a, ll b, ll& x, ll& y){
	if(!b){x = 1; y = 0;}
	else{gcd(b, a%b, y,x); y -= x*(a/b);}
}

int dfs(int node){
	if(vis[node]) return s[node];
	vis[node] = 1;
	ll ans = 0;
	for(auto k: graph[node]){
		ans += dfs(k);
	}
	return s[node] = ans+1;
}

inline ll mod(ll k){return k%p<0?k%p+p:k%p;}

int main(){
	//freopen("data.out", "w", stdout);
	fac[1] = fac[0] = 1;
	ll x,y;
	for(ll i = 1; i <= 40000; i++){
		fac[i] = (fac[i-1]*i)%p;
	}
	int t; cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 1; i <= n; i++) graph[i].clear();
		for(int i = 0; i < m; i++){
			int a,b;
			cin>>a>>b;
			graph[b].push_back(a);
		}
		memset(vis,0,sizeof vis);
		memset(s,0,sizeof s);
		for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
		ll denom = 1;
		for(int i = 1; i <= n; i++){
			denom *= s[i]; 
			denom %= p;
		}
		gcd(denom,p,x,y);
		ll ans = mod(fac[n]*x);
		cout<<ans<<endl;
			
	}
	
}