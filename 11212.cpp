#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int list[10],chd[10];
int maxd;
int ans;

int right(){
	int right = 0;
	for(int i = 0; i < n; i++)
		if(chd[i] == i + 1) right++;
	return right;
}

void move(int begin, int end, int pos){
	int pre, after, cur = 0, b, e;
	for(int i = 0; i < n; i++){
		list[i] = chd[cur];
		cur = chd[cur];
	}
	b = list[begin];
	e = list[end];
	if(!begin) pre = 0;
	else pre = list[begin - 1];
	if(end == n -1 ) after = 0;
	else after = list[end+1];
	chd[pre] = after;
	chd[e] = chd[pos];
	chd[pos] = b;
}

bool dfs(int d){
	int r = right();
	if(r==n) {return true;}
	if(n-r > 3*(maxd - d)) return false;
	if(d>=maxd) return false;
	int cpy[10];
	memcpy(cpy, chd, sizeof chd);
	for(int i = 0; i < n;i++){
		for(int j = i; j < n;j++){
			for(int pos = 0; pos<=n; pos++){
				if(pos>=i&&pos<=j)continue;
				move(i,j,pos);
				if(dfs(d + 1)) return true;
				memcpy(chd, cpy,sizeof cpy);
			}
		}
	}
	return false;
}

int main(){
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	
	
	int kase = 0;
	while(cin>>n && n){
		kase++;
		int cur = 0;
		memset(chd, 0, sizeof chd);
		for(int i = 0; i < n; i++){
			int c = cur;
			cin>>cur;
			chd[c] = cur;
		}
		ans = 0;
		for(int i = 0;i < n;i++ ){
			maxd = i;
			if(dfs(0)) {ans = i; break;}
		}
		cout<<"Case "<<kase<<": "<<ans<<endl;
	}
}
