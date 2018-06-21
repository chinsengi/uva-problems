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

int n;
int blocks[31][3];
int d[31][3];
bool g[31][3][31][3];

bool ok(int n1, int n2, int d1, int d2){
	vector<int> sides = {0,1,2};
	sides.erase(sides.begin()+d1);
	int x1 = blocks[n1][sides[0]];
	int y1 = blocks[n1][sides[1]];
	sides = {0,1,2};
	sides.erase(sides.begin()+d2);
	int x2 = blocks[n2][sides[0]];
	int y2 = blocks[n2][sides[1]];
	return (x1>x2&&y1>y2)||(y1>x2&&x1>y2);
}

int dp(int nb, int dir){
	if(d[nb][dir]!=0) return d[nb][dir];
	int& height = d[nb][dir];
	int h = blocks[nb][dir];
	height = h;
	for(int i = 0; i <n; i++)
		for(int j = 0; j < 3; j++) if(g[nb][dir][i][j]){
				height = max(height, dp(i,j)+h);
		}
	return height;
}


int main(){
	int kase = 0;
	while(cin>>n&&n){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 3; j++){
				cin>>blocks[i][j];
			}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 3; j++)
				for(int k = 0; k < n; k++)
					for(int l = 0; l < 3; l++){
						g[i][j][k][l] = ok(i,k,j,l);
					}
		memset(d,0,sizeof d);
		int m = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 3; j++){
				d[i][j] = dp(i,j);
				m = max(m,d[i][j]);
			}
		cout<<"Case "<<++kase<<": maximum height = "<<m<<endl;
	}
}