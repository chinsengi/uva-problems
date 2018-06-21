#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 100;

char s[maxn];
bool failed;
vector<int> ans;

struct Node{
	bool have_value;
	int v;
	Node *left, *right;
	Node(): have_value(false), left(NULL), right(NULL) {}
};


Node* newnode() {return new Node();}
Node* root = newnode();

void addnode(int v, char* s){
	int n = strlen(s);
	Node* u = root;
	for(int i = 0; i < n ; i++){
		if(s[i] == 'L') {
			if(u->left == NULL) u->left = newnode();
			u = u->left;
		}else if(s[i] == 'R'){
			if(u->right == NULL) u->right = newnode();
			u = u->right;
		}
	}
	if(u->have_value) failed = true;
	u->v = v;
	u->have_value = true;
}

bool bfs(vector<int>& ans){  //revise ans itself
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while(!q.empty()){
		Node* u = q.front(); q.pop();
		if(!u->have_value) return false;
		ans.push_back(u->v);
		if(u->left != NULL) q.push(u->left);
		if(u->right != NULL) q.push(u->right);
		
	}
	return true;
}

void remove_tree(Node* u){
	if(u == NULL) return;
	remove_tree(u-> left);
	remove_tree(u->right);
	delete u;
}

bool read_input(){
	failed = false;
	root = newnode();
	for(;;){
		if(scanf("%s", s) != 1) return false;
		if(!strcmp(s, "()")) break;
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s,',') + 1);
	}
	return true;
}

int main(){
	while(read_input()){
		if(failed || !bfs(ans)){
			printf("not complete\n");
		}else{
			for(int i = 0; i < ans.size() - 1; i++)
				printf("%d ", ans[i]);
			printf("%d", ans[ans.size() - 1]);
			printf("\n");
		}
		remove_tree(root);
		
	}
	
	
}






























