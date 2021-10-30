#include<bits/stdc++.h>
using namespace std;

int n, m; 
char a[1005][1005];
int go[1005][1005];//去ans[go[x][y]]找答案 
int ans[100005];
int res = 0;
char tag1 = '0';//表示字符为tag1 
char tag2 = '1';

void dfs(int x, int y, int pre, int flag){
	if(x < 1 || x > n || y < 1 || y > n || a[x][y]-'0' != pre || go[x][y] != -1) return;
//	if(go[x][y] != -1){
//		cout << ans[go[x][y]] << endl;
//		return;
//	} 
	
	go[x][y] = flag;
	ans[flag]++;
	
	dfs(x-1, y, !pre, flag);
	dfs(x+1, y, !pre, flag);
	dfs(x, y-1, !pre, flag); 
	dfs(x, y+1, !pre, flag);
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
//		getchar();
	}
	memset(go, -1, sizeof(go));
	int x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		dfs(x, y, a[x][y]-'0', i);
		cout << ans[go[x][y]] << endl;
	} 


}
