#include<cstdio>
#include<cstring>
#define maxn 100
char s[maxn];
int main()
{
	int c = 0, T, score;
	char a;
	scanf("%d", &T);
	while(T--){
		score = 0;
		c = 0;
		scanf("%s",s);
		int len = strlen(s);
		for(int i = 0; i < len; i++){
			if(s[i] == 'O'){
				score = score + c + 1;
				c++;
				
			}else{
				c = 0;
			}
		}
		printf("%d\n", score);
		
	}
	
}