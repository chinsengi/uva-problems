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

const int maxn = 15;
char grid[maxn][maxn];
int n;
int main(){
	int t;
	cin>>t;
	int kase=0;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin>>grid[i][j];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(grid[i][j]!='.') continue;
				for(int k = 'A'; k <= 'Z'; k++){
					if(i>0&&grid[i-1][j]==k)continue;
					if(j>0&&grid[i][j-1]==k)continue;
					if(i<n-1&&grid[i+1][j]==k)continue;
					if(j<n-1&&grid[i][j+1]==k)continue;
					grid[i][j] = (char)k;
					break;
				}
			}
		}
		cout<<"Case "<<++kase<<":\n";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout<<grid[i][j];
			cout<<endl;
		}
			
	}
}