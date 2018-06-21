#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int grid[15][105];
int path[15][105];
long long d[15][105];
int n, m;


int main(){
//	freopen("data.out", "w", stdout);
//	freopen("data.in", "r", stdin);
	while(cin>>n&&cin>>m){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin>>grid[i][j];
		for(int i = 0; i < n; i ++)
			d[i][m-1] = grid[i][m-1];
		for(int i = m - 2; i >=0; i--){
			for(int j = 0; j < n; j++){
				d[j][i] = (1<<30);
				if(j == 0){
					if(d[0][i+1]+grid[j][i]<d[j][i]) {d[j][i] = d[0][i+1]+grid[j][i];  path[j][i] = j;}
					if(d[1][i+1]+grid[j][i]<d[j][i]&&1<n)  {d[j][i] = d[1][i+1]+grid[j][i];  path[j][i] = j+1;}
					if(d[n-1][i+1]+grid[j][i]<d[j][i]) {d[j][i] = d[n-1][i+1]+grid[j][i]; path[j][i] = n-1;}
				}else if(j==n-1){
					if(d[0][i+1]+grid[j][i]<d[j][i]) {d[j][i] = d[0][i+1]+grid[j][i]; path[j][i] = 0;}
					if(d[n-2][i+1]+grid[j][i]<d[j][i]&&n-2>0)  {d[j][i] = d[n-2][i+1]+grid[j][i]; path[j][i] = j-1;}
					if(d[n-1][i+1]+grid[j][i]<d[j][i]) {d[j][i] = d[n-1][i+1]+grid[j][i]; path[j][i] = j;}
				}else{
					if(d[j-1][i+1]+grid[j][i]<d[j][i]&&j - 1>=0) {d[j][i] = d[j-1][i+1]+grid[j][i]; path[j][i] = j - 1;}
					if(d[j][i+1]+grid[j][i]<d[j][i])  {d[j][i] = d[j][i+1]+grid[j][i]; path[j][i] = j;}
					if(d[j+1][i+1]+grid[j][i]<d[j][i]&&j+1<n) {d[j][i] = d[j+1][i+1]+grid[j][i]; path[j][i] = j+1;}
				}
			}
		}
		int ans = d[0][0];
		int start = 0;
		for(int i = 1; i < n; i++){
			if(d[i][0]<ans) {start = i;ans = d[i][0];}
		}
		int cur = start;
		cout<<cur + 1;
		for(int j = 0; j < m-1; j++){			
			cur = path[cur][j];
			cout<<" "<<cur+1;
		}
		cout<<"\n";
		cout<<ans<<endl;
		
		
	}
}