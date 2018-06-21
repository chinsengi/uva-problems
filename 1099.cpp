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

const int maxn = 105;
int n,x,y;
int bar[20];
int d[1<<15+5][maxn];
int sum[1<<15+5];


int bitcount(int x){return x==0 ? 0 : bitcount(x/2)+ (x&1);}

int dp(int s, int r){
	if(d[s][r] != -1) return d[s][r];
	int c = sum[s]/r;
	if(bitcount(s)==1) return d[s][r]=1;
	int& ans = d[s][r];
	for(int s0 = (s-1)&s; s0; s0 = (s0-1)&s){
		int s1 = s-s0;
		if((sum[s0]%r==0)&&dp(s0,min(sum[s0]/r, r))&&dp(s1,min(sum[s1]/r,r))) {return ans = 1;}
		if((sum[s0]%c==0)&&dp(s0,min(sum[s0]/c, c))&&dp(s1,min(sum[s1]/c,c))) {return ans = 1;}
	}
	return ans = 0;
}



int main(){
	for(int kase = 1;cin>>n>>x>>y&&n; kase++){
		int s= 0;
		rep(i,0,n) {cin>>bar[i];s+=bar[i];}
		cout<<"Case "<<kase<<": ";
		if(s!= x*y) {cout<<"No"<<endl;continue;}
		memset(d,-1,sizeof d);
		memset(sum,0,sizeof sum);
		rep(s,0,1<<n) rep(i,0,n)if(s&(1<<i)){
			sum[s] += bar[i];
		}
		if(dp((1<<n)-1,min(x,y)))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}