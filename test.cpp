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

const int maxn = 100;
string pre[100000000];

ostream& operator << (ostream& os, const ii& p) {
	return os<<p.first<<" "<<p.second;
}

ii operator + (ii& a, ii& b){
	return make_pair(a.first+b.first, a.second+b.second);
}

int main(){
	ii a(1,2);
	ii b(2,3);
	ii c = (a+b);
	cout<<(a+b);
}
