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

const int maxn = 1200;
int n;
int vis[maxn][maxn];
ii p[maxn][maxn];
ii after[maxn][maxn];
string per[] = {"id", "rot", "sym","bhsym", "bvsym", "div", "mix", "id-", "rot-", "sym-","bhsym-", "bvsym-", "div-", "mix-"};
vii cycles[maxn*maxn];


void permutation(int i){
	switch(i){
		case 0: rep(i,0,n) rep(j,0,n)after[i][j] = p[i][j]; break;
		case 1:
			rep(i,0,n) rep(j,0,n){
				after[-j+n-1][i] = p[i][j];
			}
			break;
		case 2:
			rep(i,0,n) rep(j,0,n) after[i][j] = p[i][n-1-j];
			break;
		case 3:
			rep(i,0,n) rep(j,0,n) if(i>=n/2)after[i][j] = p[i][n-1-j]; else after[i][j] = p[i][j];
			break;
		case 4:
			rep(i,0,n) rep(j,0,n) if(i>=n/2) after[i][j] = p[3*n/2-1-i][j]; else after[i][j] = p[i][j];
			break;
		case 5:
			rep(i,0,n) rep(j,0,n) if(i>=n/2)after[i][j] = p[2*i-n+1][j]; else after[i][j] = p[2*i][j];
			break;
		case 6:
			rep(i,0,n) rep(j,0,n){
				if(i%2){
					if(j%2) after[i][j] = p[i][n/2+j/2];
					else after[i][j] = p[i-1][n/2+j/2];
				}else{
					if(j%2) after[i][j] = p[i+1][j/2];
					else after[i][j] = p[i][j/2];
				}
			} 
			break;	
		case 7: permutation(i-7); return;
		case 8: 
			rep(i,0,n) rep(j,0,n){
				after[i][j] = p[-j+n-1][i];
			}
			break;
		case 9: permutation(i-7); return;
		case 10: permutation(i-7); return;
		case 11: permutation(i-7); return;
		case 12: 
			rep(i,0,n) rep(j,0,n) if(i>=n/2)after[2*i-n+1][j] = p[i][j]; else after[2*i][j] = p[i][j];
			break;
		case 13:
			rep(i,0,n) rep(j,0,n){
				if(i%2){
					if(j%2) after[i][n/2+j/2] = p[i][j];
					else after[i-1][n/2+j/2] = p[i][j];
				}else{
					if(j%2) after[i+1][j/2] = p[i][j];
					else after[i][j/2] = p[i][j];
				}
			} 
			break;
	}
	memcpy(p, after,sizeof after);
}

int gcd(int a, int b){
	return b==0? a:gcd(b, a%b);
}

int main(){
	//freopen("data.out", "w", stdout);
	int t, nc = 0;
	cin>>t>>n;
	
	while(t--){
		vector<string> orders;
		int n2;
		for(;;){
			string s;
			if(!(cin>>s)) break;
			if(isdigit(s[0])) {sscanf(s.c_str(),"%d", &n2); break;}
			orders.push_back(s);
		} 
		rep(i,0,n) rep(j,0,n) p[i][j] = ii (i,j);
		for(int i = orders.size()-1; i >=0; i--){
			int j = find(per, per+14, orders[i])-per;
			permutation(j);
		}
		rep(i,0,nc)cycles[i].clear();
		memset(vis,0,sizeof vis);
		nc = 0;//number of cycles
		rep(i,0,n) rep(j,0,n){
			if(vis[i][j]) continue;
			int m = i, n = j;
			while(!vis[m][n]){
				vis[m][n] = 1;
				cycles[nc].push_back(ii (m,n));
				ii tmp = p[m][n];
				m = tmp.first;
				n = tmp.second;
			}
			nc++;
		}
		int ans = 1;
		rep(i,0,nc){
			int si = cycles[i].size();
			ans = ans/gcd(ans, si)*si;
		}
		cout<<ans<<endl;
		if(t) cout<<endl;
		n = n2;
	}
}
























