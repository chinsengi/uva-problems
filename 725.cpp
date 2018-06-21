#include<cstdio>
#include<cstring>

int s[10];

int main(){
	int n;
	scanf("%d", &n);
	while(n){
		memset(s, 0, sizeof(s));
		bool e = false;
		for(int i = 1234; i <= 98765; i++){
			memset(s, 0, sizeof(s));
			bool flag = true;
			int k = i;
			for(int j = 0; j < 5; j++){
				if(!s[k%10]) s[k%10]++;
				else {flag = false; break;}
				k/= 10;
			}
			int a = n*i;
			if(a > 99999) continue;
			if(flag) for(int j = 0; j < 5; j++){
				if(!s[a%10]) s[a%10]++;
				else {flag = false; break;}
				a/=10;
			}
			if(flag&&i < 10000){
				printf("%d / 0%d = %d\n", n*i, i, n);e = true;
			}else if(flag&&i> 10000){
				printf("%d / %d = %d\n", n*i, i, n);e = true;
			}
		}
		if(!e) printf("There are no solutions for %d.\n", n);
		scanf("%d", &n);
		if(n) printf("\n");
	}
}