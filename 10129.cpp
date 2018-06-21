#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 1000+10;

char s[maxn];
int g[26][2];//0:= out; 1:= in
int pic[26][26];
int vis[26];

void dfs(int b){
	vis[b] = 1;
	for(int i = 0; i < 26; i++){
		if(vis[i] == 0 && pic[b][i]){
			dfs(i);
		}
	}
	return;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		memset(g, 0, sizeof(g));
		memset(vis,-1, sizeof(vis));
		memset(pic,0, sizeof(pic));
		int begin, end;
		for(int i = 0; i < n; i++){
			scanf("%s",s);
			begin = s[0] - 'a';
			end = s[strlen(s) - 1] - 'a';
			pic[begin][end] = 1;
			pic[end][begin] = 1;
			g[begin][0]++;
			g[end][1]++;
			vis[begin] = 0; vis[end] = 0;
		}
		int odd = 0;
		bool flag = true;
		for(int i = 0; i < 26; i++){
			int a = g[i][0];
			int b = g[i][1];
			if(a != b){
				if(abs(a-b) == 1 && odd<=1) odd++;
				else {flag = false;break;}
				flag = !flag;
			}
		}
		dfs(begin);
		for(int i = 0; i < 26; i++)
			if(vis[i] == 0) {flag = false; break;}
		if(!flag) printf("The door cannot be opened.\n");
		else printf("Ordering is possible.\n");
	}
}