#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
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



unsigned long long dp[21][21];

int main(){
	//freopen("data.out", "w", stdout);
	memset(dp,0,sizeof dp);
	dp[1][0] = 1;
	for(int i = 2; i < 22; i++)
		for(int j = 0; j < i; j++){
		dp[i][j] = dp[i-1][j];
        if(j > 0) dp[i][j] += dp[i-1][j-1] * (i-1);
	}
	int n, k;
	while(cin>>n>>k&&n){
		cout<<dp[n][k]<<endl;
	}
}