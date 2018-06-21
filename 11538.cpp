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

#define rep(i, s, n) for(ll i = s; i < n; i++)
typedef unsigned long long ll;
ll m,n;

int main(){
	while(cin>>m>>n&&m){
		ll ans = 0;
		ans +=m*n*(m+n-2);
		ll mi = min(m,n);
		ll md;
		if(m!=n) md = mi*(mi+1)*(2*mi+1)/3-mi*(mi+1)+(m+n-1-2*mi)*(mi-1)*mi;
		if(m==n) md = mi*(mi+1)*(2*mi+1)/3-mi*(mi+1)-m*(m-1);
		/*
		rep(i,0,m){
			ll tmp = min(n,i+1);
			md+= tmp*(tmp-1);
		}
		rep(i,0,n-1){
			ll tmp = min(m,i+1);
			md+= tmp*(tmp-1);
		}
		*/
		ans += md*2;
		cout<<ans<<endl;
	}
}