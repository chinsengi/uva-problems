#include<cstdio>
#include<cstring>
#include<cctype>
#define maxn 100

char s[maxn];\
int T;

int main(){
	double mass[] = {12.01, 1.008, 16.00, 14.01};
	scanf("%d", &T);
	double m,result;
	while(T--){
		scanf("%s",s);
		int len = strlen(s);
		result = 0;
		for(int i = 0; i < len; i++){
			if(s[i] <= '9') continue;
			switch(s[i]){
				case 'C': m = mass[0];break;
				case 'H': m = mass[1];break;
				case 'O': m = mass[2];break;
				case 'N': m = mass[3];break;
			}
			if(i == len - 1){
				result += m;
				continue;
			}
			if(isalpha(s[i + 1])){
				result += m;
			}else if(isdigit(s[i + 1])&&isdigit(s[i+2])){
				result += m*(10*(s[i+1]-48) + s[i + 2]-48);
			}else{
				result += m * (s[i +1]-48);
			}	
		}
		printf("%.3lf\n", result);
	}
}