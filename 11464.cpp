#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 20;
const int INF = 1000000000;
int a[maxn][maxn], b[maxn][maxn];
int n;


int check(int s){
	memset(b, 0, sizeof b);
	for(int c = 0; c < n; c++){
		if(s & (1<<c)) b[0][c] = 1;
		else if(a[0][c] == 1) return INF;
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n; j++){
			int p = 0;
			if(i-2>=0&&b[i-2][j]==1)p++;
			if(j-1>=0&&b[i-1][j-1]==1)p++;
			if(j+1<n&&b[i-1][j+1]==1)p++;
			if(p%2==1) b[i][j] = 1;
			else b[i][j] = 0;
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 1&&b[i][j] == 0) return INF;
			if(a[i][j] == 0&&b[i][j] == 1) cnt++;
		}
	}
	return cnt;
	
}




int main(){
	int kase = 0;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin>>a[i][j];
		int ans = INF;	
		for(int s = 0; s < 1<<n; s++){
			ans = min(ans, check(s));
		}
		if(ans == INF) ans = -1;
		cout<<"Case "<<++kase<<": "<<ans<<endl;
	}
}