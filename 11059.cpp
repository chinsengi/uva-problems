#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int t, kase = 0;
int s[20];


ll product(int begin, int end){
    ll product = 1;
    for(int i = begin; i <= end; i++)
        product *= s[i];
    return product;
}


int main(){
 //   freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    while(scanf("%d", &t) != EOF){
        kase++;
        long long maxp = 0;
        for(int i = 0; i < t; i++){
            scanf("%d", &s[i]);
        }
        for(int i = 0; i < t; i++){
            for(int j = i; j < t; j++){
                ll p = product(i, j);
                if(p > maxp) maxp = p;
            }
        }


        printf("Case #%d: The maximum product is ", kase); cout<<maxp<<".\n\n";
    }


}

