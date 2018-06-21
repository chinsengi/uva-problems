#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<cctype>
#include<algorithm>
using namespace std;

const string tiles[] = {
	"1T","2T","3T","4T","5T","6T","7T","8T","9T",
	"1S","2S","3S","4S","5S","6S","7S","8S","9S",
	"1W","2W","3W","4W","5W","6W","7W","8W","9W",
	"DONG", "NAN", "XI", "BEI",
	"ZHONG", "FA", "BAI"
};
int hand[34];

void convert(char* name){
	string s(name);
	for(int i = 0; i < 34; i++){
		if(tiles[i] == s) hand[i]++;
	}
	return;
}

bool search(int* h){
	int tmp[34];
	memcpy(tmp, h, sizeof tmp);
	for(int i = 0; i < 34; i++){
		if(tmp[i] == 0)continue;
		if(tmp[i] == 1||tmp[i] ==2){
			if(i%9>6||i>26||tmp[i+1]==0||tmp[i+2]==0) return false;
			else{
				tmp[i]--;tmp[i+1]--;tmp[i+2]--;
				return search(tmp);
			}
		}
		if(tmp[i]==3||tmp[i]==4){
			bool pong, chow;
			tmp[i]-=3;
			pong = search(tmp);
			tmp[i]+=3;
			if(i%9>6||i>26||tmp[i+1]==0||tmp[i+2]==0) chow = false;
			else{
				tmp[i]--;tmp[i+1]--;tmp[i+2]--;
				chow = search(tmp);
			}
			return pong||chow;
		}
	}
	return true;
}

int main(){
//freopen("data.out", "w", stdout);
	char s[10];
	int kase = 0;
	vector<int> ans;
	while(scanf("%s", s)==1){
		ans.clear();
		memset(hand,0,sizeof hand);
		if(s[0]=='0') break;
		cout<<"Case "<<++kase<<":";
		convert(s);
		for(int i = 0; i < 12; i++){
			scanf("%s",s);
			convert(s);
		}
		bool ready = false;
		for(int j = 0; j < 34; j++){
			if(hand[j]==4) continue;
			hand[j]++;
			bool ok = false;
			for(int i = 0; i < 34; i++){
				if(hand[i]<=1) continue;
				hand[i] -= 2;
				if(search(hand)) {ok = true;hand[i]+=2; break;}
				hand[i] += 2;
			}
			if(ok) {cout<<" "<<tiles[j];ready = true;}
			hand[j]--;
		}
		if(!ready) cout<<" Not ready";
		cout<<endl;
	}
}