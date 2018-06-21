#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
int n;
ll ans[2000+5];
int number[] = {2,5,5,4,5,6,3,7,6};

int main(){
	memset(ans,0,sizeof ans);
	ans[0] = ans[1] = 0;
	for(int i = 2; i <= 2000; i++){
		for(int a: number){
			if(a>i)continue;
			else ans[i] += ans[i-a] + 1;
		}
		if(i>=6) ans[i]+= ans[i-6];
	}
	while(cin>>n){
		if(n>=6) cout<<ans[n]+1<<endl;
		else cout<<ans[n]<<endl;
	}
}