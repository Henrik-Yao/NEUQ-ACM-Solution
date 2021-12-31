#include <iostream>
#include <string>

using namespace std;

const int N = 1009;

char map[N][N];
int ans[N][N];
int a[N*N];
int n;

void dfs(int x, int y, int k) {
//	printf("x = %d, y = %d, ans[x][y] = %d\n", x, y, ans[x][y]);
	if(ans[x][y]) return;
	ans[x][y] = k;
	a[k] ++;
//	printf("a[k] = %d\n", a[k]);
	
	if(map[x][y] != map[x+1][y] && x+1<=n) dfs(x+1,y, k);
	if(map[x][y] != map[x][y+1] && y+1<=n) dfs(x,y+1, k);
	if(map[x][y] != map[x-1][y] && x-1>=1) dfs(x-1,y, k);
	if(map[x][y] != map[x][y-1] && y-1>=1) dfs(x,y-1, k);
	
}

int main (){
	int m;
	string u;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
//		cin >> u;
//		cout << "u = " << u << endl;
		for (int j = 1; j <= n; j++) {
//			map[i][j] = u[j-1];
			cin >> map[i][j];
		}
	}
	
	int k = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(!ans[i][j]) dfs(i, j, k++);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	while(m--) {
		int x, y;
		cin >> x >> y;
//		printf("x = %d, y = %d, ans[x][y] = %d, a[ans[x][y]] = %d\n",x, y, ans[x][y], a[ans[x][y]]);
		cout << a[ans[x][y]];
		if(m) cout << endl;
	}
	
	return 0;
}
