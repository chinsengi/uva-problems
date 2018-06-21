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
const int maxn = 1<<16+5;
int n,kase;
int cover[maxn];
int p[20];
int f[maxn];

int main(){
	while(cin>>n&&n){
		memset(p,0,sizeof p);
		rep(i,0,n){
			p[i] += 1<<i;
			int m; cin>>m;
			rep(j,0,m) {int a; cin>>a; p[i] += 1<<a;}
		}
		rep(i,0,1<<n){
			cover[i] = 0;
			rep(j,0,n) if(i & (1<<j)) cover[i] |= p[j];
		}
		f[0] = 0;
		int all = (1<<n)-1;
		for(int s = 1; s< 1<<n; s++){
			f[s] = 0;
			for(int s0 = s; s0; s0 = (s0 - 1)&s ){
				if(cover[s0] == all) f[s] = max(f[s], f[s^s0] + 1);
			}
		}
		cout<<"Case "<<++kase<<": "<<f[all]<<endl;
		
	}
}