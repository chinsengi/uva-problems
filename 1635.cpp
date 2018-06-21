#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 100000+5;
int bad[maxn];

void prime_factors(int n, vector<int>& primes){
	int m = floor(sqrt(n) + 0.5);
	for(int i = 2; i <= m; i++){//attention <= instead of <
		if(n%i ==0){
			primes.push_back(i);
			while(n%i == 0) n/=i;
		}
	}
	if(n>1)primes.push_back(n);
}

int main(){
	int n, m, kase = 0;
	while(cin>>n>>m){
		vector<int> primes;
		prime_factors(m, primes);
		memset(bad,0, sizeof bad);
		n--;
		for(int i = 0; i < primes.size(); i++){
			int p = primes[i], e = 0; 
			int min_e = 0,x = m;
			while(x%p == 0){x/=p; min_e++;}//the degree of the prime factor
			for(int k = 1; k < n; k++){
				x = n - k +1;
				while(x%p == 0){x/=p; e++;}
				x = k;
				while(x%p ==0){x/=p; e--;}
				if(e < min_e) bad[k] = 1;
			}
		}
		vector<int> ans;
		for(int k = 1; k < n; k++)
			if(!bad[k]) ans.push_back(k + 1);
		cout<<ans.size()<<endl;
		if(!ans.empty()){
			cout<<ans[0];
			for(int i = 1; i < ans.size(); i++) cout<<" "<<ans[i];
		}
		cout<<endl;
	}
}
