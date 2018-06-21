#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100000+5;
ll n;
ll g[maxn];

int main(){
//	freopen("data.in","r",stdin);
	while(scanf("%d",&n)==1&&n){
		ll  sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&g[i]);
			sum+=g[i];
		}
		if(n==1){printf("%d\n",g[0]);continue;}
		ll maxsum = 0;
		for(int i = 0; i <n-1; i++){
			maxsum = max(maxsum, g[i]+g[i+1]);
		}
		maxsum = max(maxsum, g[0]+g[n-1]);
		if(!(n%2)) {printf("%d\n", maxsum);continue;}
		ll low;
		if(sum%(n/2)) low = sum/(n/2)+1;
		else low = sum/(n/2);
		printf("%d\n", max(maxsum,low));
	}
}