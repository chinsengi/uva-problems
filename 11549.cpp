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

const int maxn = 1000000000;
int n, k;
set<int> vis;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vis.clear();
		long long num = pow(10,n);
		long long m = k;
		long long tmp = k;
		vis.insert(k);
		for(;;){
			tmp = tmp*tmp;
			while(tmp >= num)tmp/= 10;
			if(vis.count(tmp)) break;
			vis.insert(tmp);
			m = max(m, tmp);
		}
		cout<<m<<endl;
			
	}
}
