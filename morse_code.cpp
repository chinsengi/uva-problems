#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<sstream>
#include<utility>
#include<deque>
#include<list>
#include<set>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<ctime>
using namespace std;

#define rep(i, s, n) for(int i = s; i < n; i++)
//1<<16 = 2^16
typedef long long  ll;
typedef pair<int, int>  ii;
typedef vector<ii> vii;
typedef vector<int> vi;

string mc[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
int l;
char morse[800];
vector<char> deco;

void decode(int s){
		if(s >= l) {rep(i,0,deco.size())printf("%c",deco[i]); printf("\n\n");return;}
		for(int i = 0; i < 26; i++){
			string letter = mc[i];
			const char* le = letter.c_str();
			int len = strlen(le);
			bool ok = true;
			rep(j,0,len) if(morse[s+j] != le[j]||s+j>=l) {ok = false; break;}
			if(ok){
				char p = i+'a';
				deco.push_back(p);
				decode(s+len);
				deco.pop_back();
			}
			
		}
}

int main(){
	freopen("data.out", "w", stdout);
	char t;
	int i = 0;
	while(cin>>t)morse[i++] = t;
	l = strlen(morse);
	decode(0);
}