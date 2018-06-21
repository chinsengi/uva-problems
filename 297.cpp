#include<cstdio>
#include<cstring>
using namespace std;

const int len = 32;
const int maxn = 1024+ 10;
char s[maxn];
int buf[len][len], cnt;

void draw(const char* s, int& p, int r, int c, int w){
	char ch = s[p++];
	if(ch == 'p'){
		draw(s, p, r, c+w/2,w/2);
		draw(s,p,r,c,w/2);
		draw(s,p,r+w/2,c,w/2);
		draw(s,p,r+w/2,c+w/2,w/2);
		
	}else if(ch == 'f'){
		for(int i = r; i < r+w; i++){
			for(int j = c; j < c + w; j++){
				if(buf[i][j] ==0){
					buf[i][j] = 1;
					cnt++;
				}
			}
		}				
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		cnt = 0;
		int p = 0;
		scanf("%s", s);
		draw(s,p,0,0,32);
		p = 0;
		scanf("%s",s);
		draw(s,p,0,0,32);
		printf("There are %d black pixels.\n", cnt);
		memset(buf, 0, sizeof(buf));
	}
	
}