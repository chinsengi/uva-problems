#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 7777+5;
char grid1[maxn][5];
char grid2[maxn][5];
int tot,k;
int at[26];
int ans[5];

void search(int d, vector<char>* c, int* x){
	if(d==5) {
		tot++;
		if(tot == k){
			for(int i = 0; i < 5; i++)
				ans[i] = x[i];
		} 
		return;
	}
	for(int i = 0; i < c[d].size(); i++){
		x[d] = i;
		search(d+1, c, x);
		
	}
		
}


int main(){
	int t; 
	cin>>t;
	while(t--){
		cin>>k;
		for(int i = 0; i < 6; i++)
			cin>>grid1[i][0]>>grid1[i][1]>>grid1[i][2]>>grid1[i][3]>>grid1[i][4];
		for(int i = 0; i < 6; i++)
			cin>>grid2[i][0]>>grid2[i][1]>>grid2[i][2]>>grid2[i][3]>>grid2[i][4];
		vector<char> c[5];
		for(int i = 0; i < 5; i++){
			memset(at, 0, sizeof at);
			for(int j = 0; j < 6; j++)
				at[grid1[j][i]-'A']=1;
			for(int j = 0; j < 6; j++)
				if(at[grid2[j][i]-'A'])at[grid2[j][i]-'A'] = -1;
			for(int j = 0; j < 26; j++)
				if(at[j] < 0) c[i].push_back('A'+j);
		}
			
		for(int i = 0; i < 5; i++)
			sort(c[i].begin(), c[i].end());
		tot = 0;
		int all = 1;
		for(int i = 0; i < 5; i++){
			all = all*c[i].size();
		}
		if(k > all)cout<<"NO";
		else{
			int x[5];
			search(0,c,x);
			for(int i = 0; i < 5; i++){
				cout<<c[i][ans[i]];
			}
		}
		cout<<endl;
	}
}