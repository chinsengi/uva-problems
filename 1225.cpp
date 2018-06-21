#include<cstdio>
#include<cstring>

int t;
int n;

int main()
{
	scanf("%d", &t);
	int result[10];
	while(t--){
		memset(result, 0, sizeof(result));
		scanf("%d", &n);
		int k;
		for(int i = 1; i <= n; i++){
			k = i;
			while(k != 0){
				result[k%10]++;
				k = k/10;
			}
		}
		for(int i = 0; i < 9; i++)
			printf("%d ", result[i]);
		printf("%d\n", result[9]);
	}
}