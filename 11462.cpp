#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int c[101];
	while(scanf("%d", &n)==1&&n){
		int tmp;
		memset(c,0,sizeof c);
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			c[tmp]++;
		}
		bool first = true;
		for(int i = 0; i <= 100; i++){
			if(c[i]==0)continue;
			int times = c[i];
			if(first) printf("%d", i);
			else printf(" %d",i);
			for(int j = 1; j < times; j++)
				printf(" %d", i);
			first = false;
		}
		printf("\n");
	}
}