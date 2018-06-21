#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int const maxn = 1000+5;
int n;
int kase;

struct task{
	int brief, exe;
	task(int a = 0, int b = 0):brief(a), exe(b){}
	
};
int cmp(const task i, const task j){return i.exe>j.exe;}
task tasks[maxn];

int main(){
	while(cin>>n&&n){
		for(int i = 0; i < n; i++){
			int a, b;
			cin>>a>>b;
			tasks[i] = task(a,b);
		}
		
		sort(tasks, tasks+n, cmp);
		int len = 0;
		int tmp = 0;
		for(int i =0; i < n; i++){
			tmp +=tasks[i].brief;
			if(tmp + tasks[i].exe > len) len = tmp + tasks[i].exe;
		}
		cout<<"Case "<<++kase<<": "<<len<<endl;
		
	}
}