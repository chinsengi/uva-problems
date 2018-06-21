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
	
long long n, m;
int nd[20], md[20];
int up;
int ans;

int main(){
	while(cin>>n>>m&&(n||m)){
		memset(nd, 0, sizeof nd);
		memset(md, 0, sizeof md);
		int i = 0;
		while(n > 0) {nd[i++] = n%10; n/=10;}
		int j = 0;
		while(m > 0) {md[j++] = m%10; m/=10;}
		int len = max(i, j);
		up = 0;
		ans = 0;
		rep(i,0,len){
			int sum = nd[i]+md[i]+up;
			if(sum>=10) {up = 1; ans++;}
			else up = 0;
		}
		if(ans == 0)cout<<"No";
		else cout<<ans;
		if(ans>1)cout<<" carry operations."<<endl;
		else cout<<" carry operation."<<endl;
	}
}