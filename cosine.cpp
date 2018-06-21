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


double coss(int* x, int* y){
	double inner = 0;
	rep(i,0,5) inner += x[i]*y[i];
	double lx = 0, ly = 0;
	rep(i,0,5) lx += x[i]*x[i];
	lx = sqrt(lx);
	rep(i,0,5) ly += y[i]*y[i];
	ly = sqrt(ly);
	return inner/(lx*ly);
}
int a[] = {1,2,0,2,0};
int b[] = {0,3,0,1,3};
int c[] = {0,2,0,2,1};
int main(){
	
	cout<<coss(a,b)<<endl;
	cout<<coss(b,c)<<endl;
	cout<<coss(c,a)<<endl;
}