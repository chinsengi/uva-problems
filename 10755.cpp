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

#define rep(i,s,t) for(int i = s; i <t; i++)
const int maxn = 21;
long long grid[maxn][maxn][maxn];
int a,b,c;

long long geta(int a1,int a2,int b1,int b2,int c1,int c2){
	long long tmp = grid[a2][b2][c2];
	if(c1!=0)tmp-=grid[a2][b2][c1-1];
	if(b1!=0)tmp-=grid[a2][b1-1][c2];
	if(b1!=0&&c1!=0)tmp += grid[a2][b1-1][c1-1];
	if(a1!=0)tmp -= grid[a1-1][b2][c2];
	if(a1!=0&&c1!=0)tmp+=grid[a1-1][b2][c1-1];
	if(a1!=0&&b1!=0)tmp+=grid[a1-1][b1-1][c2];
	if(a1!=0&&b1!=0&&c1!=0)tmp-=grid[a1-1][b1-1][c1-1];
	return tmp;
}

long long geta2(int a1,int a2,int b1,int b2,int c1,int c2, long long g){
	long long tmp = -g;
	if(c1!=0)tmp-=grid[a2][b2][c1-1];
	if(b1!=0)tmp-=grid[a2][b1-1][c2];
	if(b1!=0&&c1!=0)tmp += grid[a2][b1-1][c1-1];
	if(a1!=0)tmp -= grid[a1-1][b2][c2];
	if(a1!=0&&c1!=0)tmp+=grid[a1-1][b2][c1-1];
	if(a1!=0&&b1!=0)tmp+=grid[a1-1][b1-1][c2];
	if(a1!=0&&b1!=0&&c1!=0)tmp-=grid[a1-1][b1-1][c1-1];
	return -tmp;
}

int main(){
	//freopen("data.out", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		long long sum = 0;
		memset(grid,0, sizeof grid);
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				for(int k = 0; k < c; k++){
					long long g;
					cin>>g;
					sum+=g;
					g = geta2(i,i,j,j,k,k,g);
					grid[i][j][k] = g;
				}
			}
		}
		long long m = sum; 
		rep(a1,0,a) rep(a2,a1,a) rep(b1,0,b) rep(b2,b1,b) rep(c1,0,c) rep(c2,c1,c){
			m = max(m, geta(a1,a2,b1,b2,c1,c2));
		}
		cout<<m<<endl;
		if(t)cout<<endl;
	}
}
