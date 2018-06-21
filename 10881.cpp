#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int const maxn = 10000+5;

struct ant{
	int pos, dir, id;
	ant(int pos = 0, int dir = 0, int id = 0):pos(pos), dir(dir), id(id){} 
};

string d[] = {"L","R","Turning","Fell off"};
ant ants[maxn];
int order[maxn];
int cmp(const ant a1, const ant a2){return a1.pos<a2.pos;}

int main(){
	int t,kase = 0;
	cin>>t;
	int L, T, n;
	while(t--){
		cin>>L>>T>>n;
		for(int i = 0; i < n;i++){
			string dir;
			int pos;
			cin>>pos>>dir;
			if(dir == "L") ants[i] = ant(pos, 0, i);
			if(dir == "R") ants[i] = ant(pos, 1, i);
		}
		sort(ants, ants+n, cmp);
		for(int i = 0; i < n; i++){
			order[ants[i].id] = i;
		}
		for(int i = 0; i < n; i++){
			ant& a = ants[i];
			if(a.dir == 0) a.pos -= T;
			else a.pos += T;
			if(a.pos < 0 || a.pos > L) a.dir = 3;
		}
		sort(ants, ants+n, cmp);
		for(int i = 0; i < n; i++){
			if(ants[i].pos == ants[i+1].pos){
				ants[i].dir = 2;
				ants[i+1].dir = 2;
				i++;
			}
		}
		cout<<"Case #"<<++kase<<":"<<endl;
		for(int i  = 0; i < n; i++){
			ant& a = ants[order[i]];
			if(a.dir == 3)cout<<"Fell off"<<endl;
			else{
				cout<<a.pos<<" "<<d[a.dir]<<endl;
			}
		}
		cout<<endl;	
	}
}
