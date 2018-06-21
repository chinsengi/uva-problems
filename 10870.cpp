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
//1<<16 = 2^16
typedef long long  ll;
typedef pair<int, int>  ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int d,n,m;
deque<ll> seq;
int a[20];

int main(){
	while(cin>>d>>n>>m&&d){
		rep(i,0,d) cin>>a[i];
		seq.clear();
		rep(i,0,d) {
			ll tmp;
			cin>>tmp; seq.push_front(tmp%m);
		}
		for(int i = 0; i < n-d; i++){
			ll ans = 0;
			int k = 0;
			rep(i,0,d){
				ans += seq[i]*a[i];
			} 
			seq.pop_back();
			seq.push_front(ans%m);
		}
		cout<<seq.front()<<endl;
		
	}
}