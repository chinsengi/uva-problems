#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 50000 +5;
int phitab[maxn];

int main(){
	int n;
	memset(phitab, 0, sizeof phitab);
	phitab[1] = 1;
	for(int i = 2; i <=maxn; i++) if(!phitab[i])
		for(int j = i; j <= maxn; j+=i){
			if(!phitab[j]) phitab[j] = j;
			phitab[j] = phitab[j]/i*(i-1);
		}
	for(int i = 3; i <= maxn; i++)
		phitab[i] = phitab[i] + phitab[i-1];
	phitab[1] = 0;
	while(cin>>n&&n){
		cout<<2*phitab[n] +1<<endl;
	}
}
