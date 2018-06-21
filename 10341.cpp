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


int p,q,r,s,t,u;
const double zero = 1e-8;
double f(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;
}

int main(){

	while(cin>>p>>q>>r>>s>>t>>u){
		if(f(0)>=0&&f(1)<=0){
			double left = 0, right = 1;
			while(right-left>1e-8){
				double m = left +(right-left)/2;
				if(f(m)>=0)left = m;
				else right = m;
			}
			printf("%.4lf\n",right);
		}else cout<<"No solution\n";
	}
}