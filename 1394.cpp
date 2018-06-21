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
int n,k,m;
int dp[10005];


int main(){
	while(cin>>n>>k>>m&&n){
		memset(dp,0, sizeof dp);
		dp[1] = 0;
		rep(i,1,n+1){
			dp[i] = (dp[i-1]+k)%i;
		}
		int ans = (dp[n-1]+m)%n+1;
		cout<<ans<<endl;
	}
}
