#include<cstdio>
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

const int maxn = 1005;

int out[maxn]; 
int main(){
	int n;
	while(scanf("%d", &n) && n != 0){
		for(;;){
			stack<int> train;
			train.push(0);
			memset(out, 0, sizeof(out));
			scanf("%d", &out[0]);
			if(!out[0]) break;
			for(int i = 1; i < n; i++)
				scanf("%d", &out[i]);
			int begin = 1;
			bool flag = 1;
			for(int i = 0; i < n; i++){
				if(out[i] < train.top()){cout<<"No"<<endl; flag = false; break;}
				else if (out[i] > train.top()){
					for(int j = begin; j <= out[i]; j++) 
						train.push(j);
					begin = out[i] + 1;
					train.pop();
				}else{
					train.pop();
				}
			}
			if(flag) cout<<"Yes"<<endl;
		}
		cout<<endl;
	}
}