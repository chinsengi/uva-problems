#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

struct Node{
	int r, c;
	int dir;
	Node(int r = 0, int c = 0, int dir = 0): r(r), c(c), dir(dir){}
};

const int maxn = 10;
const char* dirs = "NESW";
const char* turns = "FLR";
int pic[maxn][maxn];
int d[maxn][maxn][maxn];
Node p[maxn][maxn][maxn];
int has_edge[maxn][maxn][maxn][4];
int r0, c0, r1, c1, r2, c2, dir;

int dir_id(char c) {return strchr(dirs, c) - dirs; }
int turn_id(char c) {return strchr(turns, c) - turns;}

const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};



Node walk(const Node& u, int turn){
	int dir = u.dir;
	if(turn == 1) dir = (dir + 3) % 4;
	if(turn == 2) dir = (dir + 1) % 4;
	return Node(u.r + dr[dir], u.c + dc[dir], dir);
}

void print_ans(Node u){
	vector<Node> nodes;
	for(;;){
		nodes.push_back(u);
		if(d[u.r][u.c][u.dir] == 0) break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r0,c0,dir));
	
	int cnt = 0;
	for(int i = nodes.size()-1; i>=0; i--){
		if(cnt % 10 == 0) printf(" ");
		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
		if(++cnt % 10 == 0) printf("\n");
	}
	if(nodes.size()%10 != 0) printf("\n");
	
}

void solve(){
	queue<Node> q;
	memset(d, -1, sizeof(d));
	Node u = walk(Node(r0, c0, dir), 0);
	d[u.r][u.c][dir] = 0;
	q.push(u);
	while(!q.empty()){
		Node u = q.front(); q.pop();
		if(u.r == r2 && u.c == c2) {print_ans(u); return;}
		for(int i = 0; i < 3; i++){
			Node v = walk(u, i);
			if(has_edge[u.r][u.c][u.dir][i] && pic[v.r][v.c] && d[v.r][v.c][v.dir] < 0){
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf("  No Solution Possible\n");
}



int main(){
	char mn[25];
	while(scanf("%s", mn) && strcmp(mn, "END")){
		memset(pic, 0,sizeof(pic));
		memset(d, 0,sizeof(d));
		memset(p, 0,sizeof(p));
		memset(has_edge, 0,sizeof(has_edge));
		char tmp;
		cin>>r0>>c0>>tmp>>r2>>c2;
		dir = dir_id(tmp);
		pic[r2][c2] = 1;
		int r,c;	
		while(cin>>r && r){
			cin>>c;
			pic[r][c] = 1;
			char s[10];
			while(scanf("%s", s) && strcmp(s, "*")){
				int di = dir_id(s[0]);
				for(int i = 1; s[i] != 0; i++){
					has_edge[r][c][di][turn_id(s[i])] = 1;
				}
			}
		}
		printf("%s\n", mn);
		solve();
	}
}

















