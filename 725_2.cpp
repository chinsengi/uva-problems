#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int n, kase = 0;
	char buf[99];
	while(scanf("%d", &n)&&n){
		int cnt = 0;
		if(kase++) printf("\n");
		for(int f = 1234;;f++){
			int a = f * n;
			sprintf(buf, "%05d%05d", a, f);
			if(strlen(buf) > 10) break;
			sort(buf, buf + 10);
			bool ok = true;
			for(int i = 0; i < 10; i++)
                if(buf[i] != '0' + i) ok = false;
            if(ok){
                cnt++;
                printf("%05d / %05d = %d\n", a, f, n);
            }
		}
		if(!cnt) printf("There are no solutions for %d.\n", n);
	}
}
