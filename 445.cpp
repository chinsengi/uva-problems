#include<cstdio>
#include<cstring>
#include<cctype>


int main()
{
	char p;
	int c;
	int times = 0;
	while((c = getchar()) != EOF){
		if(c == '\n'|| c =='!'){
			printf("\n"); continue;
		} 
		if(isdigit(c)){
			times += (c - '0');continue;
		} 
		if(isalpha(c) || c == '*'){
			if(c == 'b'){
				p = ' ';
			}else{
				p = c;
			}
			for(int i = 0; i < times; i++){
				printf("%c",p);
			}
			times = 0;
		} 
	}
}