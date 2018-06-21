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
const int p = 1000007;
const int maxn = 500+10;
int m,n,k;
int c[maxn][maxn];
void gcd(int a, int b, int& x, int& y){
	if(!b) {x = 1; y = 0;}
	else{gcd(b, a%b, y,x); y-=x*(a/b);}
}

inline int mod(int a){return a%p<0 ? a%p+p : a%p;}

int comb(int a){
	if(a<k) return 0;
	return c[a][k];
}

int main(){
	//freopen("data.out", "w", stdout);
	memset(c,0,sizeof c);
	rep(i,0,maxn)c[i][0] = c[i][i] = 1;
	for(int i = 1; i < maxn; i++){
		for(int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j]+ c[i-1][j-1])%p;
	}
	int t; cin>>t;
	for(int kase = 1; kase<=t; kase++){
		cout<<"Case "<<kase<<": ";
		cin>>m>>n>>k;
		if(k>m*n||k<2){cout<<0<<endl;continue;}
		int ans = comb(m*n) - 2*comb(m*(n-1)) - 2*comb((m-1)*n)+4*comb((m-1)*(n-1));
		ans +=(comb((m-2)*n)+comb(m*(n-2))-2*comb((m-1)*(n-2))-2*comb((m-2)*(n-1))+comb((m-2)*(n-2)));
		cout<<mod(ans)<<endl;
	}
}