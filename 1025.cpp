#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;

const int INF = 1000;
int n, T, t[55],tsum[55], m1, d[55], m2, e[55];
int dp[205][55];
int has_train[1300][55][2];
int main(){
//	freopen("data.out","w",stdout);
//	freopen("data.in","r",stdin);
	int kase = 0;
	while(cin>>n&&n){
		cin>>T;
		memset(has_train,0,sizeof has_train);
		for(int i = 0; i < n-1; i++){
			cin>>t[i+1];
			tsum[i+1] = t[i+1]+tsum[i];
		}
			
		cin>>m1;
		for(int i = 0; i < m1; i++){
			cin>>d[i];
			for(int j = 1; j < n; j++){
				has_train[d[i]+tsum[j-1]][j][0] = 1;
			}
		}
		cin>>m2;
		for(int i = 0; i < m2; i++){
			cin>>e[i];
			for(int j = n; j>1;j--){
				has_train[e[i]+tsum[n-1]-tsum[j-1]][j][1] = 1;
			}
		}
		for(int i = 1; i <=n-1; i++)dp[T][i] = INF;
		dp[T][n] = 0;//the minimum waiting T at T 'T' and station n is dp[T][n]
		for(int i = T-1; i >=0; i--)
			for(int j = 1; j <= n; j++){
				dp[i][j] = dp[i+1][j] + 1;
				if(j<n&& has_train[i][j][0]&& i+t[j]<=T)
					dp[i][j] = min(dp[i+t[j]][j+1], dp[i][j]);
				if(j>1&& has_train[i][j][1]&& i+t[j-1]<=T)
					dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
			}
		cout<<"Case Number "<<++kase<<": ";
		if(dp[0][1]>=INF) cout<<"impossible"<<endl;
		else cout<<dp[0][1]<<endl;
	}
}