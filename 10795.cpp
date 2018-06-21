#include<iostream>
#include<cmath>

using namespace std;

const int maxn = 70;
int b[maxn];
int a[maxn];
int kase;
int n;
long long f(int* p, int i, int fin){
	if(i == 0) return 0;//pay attention to border condition, here i can be zero.
	if(p[i-1]==fin)return f(p, i-1,fin);
	return f(p,i-1,6-fin-p[i-1])+(1LL<<(i-1));//must use bit shift operator or wrong answer.
}


int main(){
	
	while(cin>>n&&n){
		for(int i = 0; i < n; i++){
			cin>>b[i];
		}
		for(int i = 0; i < n; i++)
			cin>>a[i];
		int k = n-1;
		while(a[k]==b[k]) k--;
		long long ans = 0;
		if(k<0) ans = 0;
		else ans = f(b,k,6-a[k]-b[k])+f(a,k,6-a[k]-b[k])+1;
		cout<<"Case "<<++kase<<": "<<ans<<endl;
	}
}