#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;

const int maxn = 1000;

deque<int> readyq;
queue<int> blockq;
int n, quantum, c[5], var[26], ip[maxn];
bool locked;
char prog[maxn][10];

void run(int pid){
	int q = quantum;
	while(q > 0){
		string p = prog[ip[pid]];
		switch(p[2]){
			case '=': 
				var[p[0] - 'a'] = isdigit(p[5]) ? (p[4]- '0') * 10 + p[5] - '0' : p[4] - '0';
				q -= c[0];
				break;
			case 'i':
				cout<< pid + 1<<": "<<var[p[6] - 'a']<<endl;
				q -= c[1];
				break;
			case 'c':
				if(locked) {blockq.push(pid); q = 0; return;}
				locked = true;
				q -= c[2];
				break;
			case 'l':
				locked = false;
				if(!blockq.empty()){
					readyq.push_front(blockq.front());
					blockq.pop();
				}
				q -= c[3];
				break;
			case 'd':
				return;
				
				
		}
		ip[pid]++;
	}
	readyq.push_back(pid);
	return;
}


int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> n >>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>quantum;
		memset(var, 0, sizeof(var));
		
		int line = 0;
		for(int i = 0; i < n; i ++){
			fgets(prog[line++], maxn,stdin);
			ip[i] = line - 1;
			while(prog[line - 1][2] != 'd')
				fgets(prog[line++], maxn, stdin);
			readyq.push_back(i);
		}
		while(!readyq.empty()){
			int id = readyq.front();
			readyq.pop_front();
			run(id);
			
		}
		if(t) printf("\n");
	}
}