#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

typedef unsigned long long ll;
const int maxn = 10005;
ll d[25][maxn];
int n;
int denom[21];

int main(){
	for(int i = 1; i <=21; i++) denom[i] = i*i*i;
	for(int i = 0; i < maxn; i++) d[1][i] = 1;
	for(int i = 2; i <= 21; i++){
		for(int j = 0; j < maxn; j++ ){
			for(int k = j; k >= 0; k -= denom[i])
				d[i][j] += d[i-1][k];
			
		}
	}
	while(cin>>n){
		cout<<d[21][n]<<endl;
	}
}