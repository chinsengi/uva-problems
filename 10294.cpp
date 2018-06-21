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


int n,t;
ll nn, nb;

int gcd(int a, int b){
	return b==0 ? a: gcd(b, a%b);
}

int main(){
	while(cin>>n && cin>>t){
		nn = 0;nb = 0;
		for(int i = 0; i < n; i++){
			nn+=pow(t,gcd(n,i));
		}
		nb+=nn;
		if(n%2) nb += n*pow(t,(n+1)/2);
		else nb += n/2*(pow(t,n/2+1)+ pow(t,n/2));
		cout<<nn/n<<" "<<nb/2/n<<endl;
	}
}