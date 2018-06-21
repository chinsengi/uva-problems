#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
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


vi cycle[26];
int vis[26];
int even[26];
int main(){
	int t;
	cin>>t;
	while(t--){
		char a[26];
		rep(i,0,26){cin>>a[i];}
		for(int i = 0; i < 26; i++) cycle[i].clear();
		memset(vis, 0, sizeof vis);
		int n = 0;
		for(int i = 0; i < 26; i++){
			if(vis[i])continue;
			int j = i;
			while(!vis[j]){
				vis[j] = 1;
				cycle[n].push_back(j);
				j = a[j]-'A';
			}
			n++;
		}
		memset(even,0,sizeof even);
		rep(i,0,26){
			if(!cycle[i].empty()&&!(cycle[i].size()%2)) even[cycle[i].size()-1]++;
		}
		bool ok = true;
		for(int i = 1; i < 26;i+=2) if(even[i]%2) ok = false;
		if(!ok) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
