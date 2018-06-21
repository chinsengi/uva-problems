#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<utility>
#include<queue>
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
typedef pair<double, double>  dd;
typedef vector<dd> vdd;
typedef vector<int> vi;

int n;
double d[1005][1005];
vdd points;

double dist(dd a, dd b){
	return hypot(abs(a.first - b.first), abs(a.second - b.second));
}

int main(){
	while(cin>>n){
		points.clear();
		rep(i,0,n){
			double a,b;
			cin>>a>>b;
			points.push_back(dd(a,b));
		}
		memset(d, 0, sizeof d);
		for(int i = n-2; i >=0; i--)
			d[n-2][i] = dist(points[n-1],points[n-2]) + dist(points[n-1], points[i]);
		for(int i = n-3; i >=1;i--)
			for(int j = i-1; j >=0; j--){
				d[i][j] = min(dist(points[j], points[i+1])+d[i+1][i], dist(points[i], points[i+1])+d[i+1][j]);
			}
		printf("%.2lf\n",dist(points[1], points[0])+d[1][0]);
	}
}