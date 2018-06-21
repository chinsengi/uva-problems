#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int const maxn = 20000+5;
int n,m;
int dragon[maxn];
int knight[maxn];
int award;


int main(){
	while(cin>>n>>m&&n){
		for(int i = 0; i<n; i++)
			cin>>dragon[i] ;
		for(int i = 0; i < m; i++)
			cin>>knight[i];
		sort(dragon, dragon+n);
		sort(knight, knight+m);
		int i = 0;
		int j = 0;
		award = 0;
		while(j<m&&i<n){
			if(dragon[i]>knight[j]) j++;
			else {i++; award += knight[j++];}
		}
		if(i != n) cout<<"Loowater is doomed!"<<endl;
		else cout<<award<<endl;
	}
}