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

const int maxn = 100000+5;
const int INF = -300005;
int s[maxn];
int n;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int diff = INF;
		cin>>s[0];
		int m = s[0];
		for(int i = 1; i < n;i++){
			cin>>s[i];
			diff = max(m - s[i], diff);
			m = max(s[i],m);
		}
		cout<<diff<<endl;
		
	}
}