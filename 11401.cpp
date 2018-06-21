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
typedef long long ll;

inline ll sum(ll k){return (k+1)*k/2;}

inline ll csum(ll k){return k*(k+1)*(2*k+1)/6;}

int main(){
	int n;
	while(cin>>n&&n>=3){
		ll ans = 0;
		ans += n*sum(n/2-1)-(csum(n/2)-sum(n/2))*3/2;
		ans += (csum(n-n/2-1)-sum(n-n/2-1))/2;
		cout<<ans<<endl;
	}
}