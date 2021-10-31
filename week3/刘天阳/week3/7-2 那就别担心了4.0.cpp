#include <iostream>
#include <vector>


using namespace std;

const int N = 509;

int ans[N];
bool v[N];
vector<int>vis[N];

int dfs(int x) {
	v[x] = 1;
	
	if(ans[x]) return ans[x];
	
	for (int i = 0; i < vis[x].size(); i++) {
		
		ans[x] += dfs(vis[x][i]);
		
	}
	return ans[x];
}

int main (){
	
	int n, m;
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		vis[a].push_back(b);
	}
	int s, e;
	cin >> s >> e;
	
	ans[e] = 1;
	dfs(s);
	bool f = 1;
	
	for (int i = 1; i <= n; i++) {
		if(v[i] && !ans[i]) f = 0;
	}
	
	cout << ans[s];
	if(f) cout << " Yes";
	else cout << " No";
	
	
	return 0;
}
