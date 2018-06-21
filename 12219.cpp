#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
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
//1<<16 = 2^16
typedef long long  ll;
typedef pair<int, int>  ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int maxn= 50000+5;
string mt[maxn];
int lch[maxn];
int rch[maxn];
int nc = 0;
map<node, int> subtree;


int build_tree(string s){
	int len = s.size();
	int p = 0, u = ++nc;
	int i = 0;
	while(s[i] != '('&& i < len) mt[u].push_back(s[i++]);
	if(i == len){lch[u] = rch[u] = 0; return u;}
	int j = i+1;
	bool ok = false;
	for(;;){
		switch(s[j]){
			case '(': p++; break;
			case ')': p--; break;
			case ',': if(!p) ok = true;break;
		}
		if(ok) break;
		j++;
	}
	lch[u] = build_tree(s.substr(i+1,j-i));
	rch[u] = build_tree(s.substr(j+1,len-j-1));
}

int main(){
	int c;
	cin>>c;
	while(c--){
		string s;
		cin>>s;
		build_tree(s);
		
	}
}