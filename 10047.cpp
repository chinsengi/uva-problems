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

const int maxn = 30;
int m, n;
char grid[maxn][maxn];
int vis[maxn][maxn][4][5];
int d[maxn][maxn][4][5];
int sx,sy,tx,ty;
int dirx[] = {-1,0,1,0};
int diry[] = {0,1,0,-1};
struct state{
	int x,y, dir, color;
};

int main(){
	int kase = 0;
	cin>>m>>n;
	if(!m)return 0;
	for(;;){
		rep(i,0,m){
			scanf("%s", grid[i]);
			rep(j,0,n){
				if(grid[i][j]=='S') {sx = i; sy = j;grid[i][j] = '.';}
				if(grid[i][j]=='T') {tx = i; ty = j; grid[i][j] = '.';}
			}
		}
		memset(vis,0,sizeof vis);
		memset(d,-1,sizeof d);
		queue<state> bfs;
		bfs.push((state){sx,sy,0,0});
		d[sx][sy][0][0] = 0;
		vis[sx][sy][0][0] = 1;
		while(!bfs.empty()){
			state tmp = bfs.front();
			bfs.pop();
			for(int i = 1; i <=3; i+=2) if(!vis[tmp.x][tmp.y][(tmp.dir+i)%4][tmp.color]){
				bfs.push((state){tmp.x,tmp.y,(tmp.dir+i)%4,tmp.color});
				vis[tmp.x][tmp.y][(tmp.dir+i)%4][tmp.color] = 1;
				d[tmp.x][tmp.y][(tmp.dir+i)%4][tmp.color] = d[tmp.x][tmp.y][tmp.dir][tmp.color]+1;
			}
			int nx = tmp.x+dirx[tmp.dir];int ny = tmp.y + diry[tmp.dir];
			if(!vis[nx][ny][tmp.dir][(tmp.color+1)%5]&&nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]!='#'){
				bfs.push((state){nx,ny,tmp.dir,(tmp.color+1)%5});
				vis[nx][ny][tmp.dir][(tmp.color+1)%5] = 1;
				d[nx][ny][tmp.dir][(tmp.color+1)%5] = d[tmp.x][tmp.y][tmp.dir][tmp.color]+1;
			}
		}
		bool ok = false;
		int ans = 10000;
		rep(i,0,4){
			if(d[tx][ty][i][0]== -1) continue;
			else{
				ok = true;
				ans = min(ans, d[tx][ty][i][0]);
			}
		}
		cout<<"Case #"<<++kase<<endl;
		if(!ok)cout<<"destination not reachable"<<endl;
		else cout<<"minimum time = "<<ans<<" sec"<<endl;
		if(cin>>m>>n&&m) printf("\n");
		else break;
	}
}