#include<bits/stdc++.h>
using namespace std;
const int k = 1e5;
char sex[k];
int fa[k],ma[k];
bool vis[k];
int flag;

void dfs(int anc,int x){
	if(vis[anc]){
		flag = 1;
		return;
	}
	if(flag || anc == -1 || anc == 0 || x > 5){
		return;
	}
	vis[anc] = 1;
	dfs(fa[anc],x+1);
	dfs(ma[anc],x+1);
}

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		// 人的编号，性别，父亲，母亲；
		int mem;
		cin >> mem;
		cin >> sex[mem] >> fa[mem] >> ma[mem]; 
		sex[fa[mem]] = 'M';
		sex[ma[mem]] = 'F';
	}
	int m;
	cin >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		flag = 0;
		memset(vis,0,sizeof(vis));
		if(sex[a] == sex[b]){
			cout << "Never Mind\n";
			continue;
		}
		dfs(a,1);
		dfs(b,1);
		if(!flag){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}
