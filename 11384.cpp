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
	double n;
	while(cin>>n){
		cout<<floor(log2(n))+1<<endl;
	}
}