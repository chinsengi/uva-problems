#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int const maxn = 1000000+5;
int n;
int coin[maxn];
int a[maxn];

int main(){
	while(cin>>n){
		long long cnt = 0;
		long long tot = 0;
		for(int i = 0; i < n; i++){
			cin>>coin[i];
			tot += coin[i];
		}
		int avg = tot/n;
		a[0] = 0;
		for(int i = 1; i <n; i++)
			a[i] = a[i-1] + avg-coin[i];
		sort(a, a+n);
		int start = a[n/2];
		for(int i = 0; i < n; i++)
			cnt+=abs(a[i] - start);
		cout<<cnt<<endl;
	}
}