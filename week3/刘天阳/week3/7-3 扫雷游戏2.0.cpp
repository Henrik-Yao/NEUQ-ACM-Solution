#include <iostream>

using namespace std;

const int N = 30;

int f[][8] = {{1,0}, {-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
bool vis[N][N];
int ans[N][N];
int n, m;

void dfs(int x, int y) {
//	printf("x = %d, y = %d\n", x, y);
	if(vis[x][y]) return;
	vis[x][y] = 1;
	
	int t = 0;
	for (int i = 0; i < 8; i++) {
		int xx = x+f[i][0], yy = y+f[i][1];
		if(xx > n || xx == 0) continue;
		if(yy > m || yy == 0) continue;
		if(ans[xx][yy] == -1) {
			t ++ ;
//			printf("xx1 = %d, yy1 = %d\n", xx, yy);
		}
	} 
	
	ans[x][y] = t;
//	printf("t = %d\n", t);
	
	if(ans[x][y]==0) {
		for (int i = 0; i < 8; i++) {
			int xx = x+f[i][0], yy = y+f[i][1];
//			
			if(xx > n || xx == 0) continue;
			if(yy > m || yy == 0) continue;
//			printf("xx = %d, yy = %d, i = %d\n", xx, yy, i);
			if(ans[xx][yy] != -1 && !vis[xx][yy]) dfs(xx, yy);
		} 
	}
}

int main (){
	int k, l;
	
	cin >> n >> m >> k >> l;
	
	while(k--) {
		int x, y;
		cin >> x >> y;
		ans[++x][++y] = -1;
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << ans[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	while(l--) {
		int x, y;
		cin >> x >> y;
		++x, ++y;
		if(!vis[x][y]) {
			if(ans[x][y] == -1) {
				cout << "You lose";
				break;
			}
			else {
				dfs(x, y);
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if(ans[i][j] != -1) {
							if(vis[i][j]) cout << ans[i][j] << " ";
							else cout << "-1 ";
						}
						else cout << "-1 ";
					}
					cout << endl;
				}
				bool ju = 1;
				for(int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						if(!vis[i][j] && ans[i][j] != -1){
							ju = 0;
//							printf("i = %d, j = %d\n", i, j);
							break;
						}
					}
				}
				if(ju) cout << "You win" << endl; 
				else cout << endl;
				
			}
		}
		cout << endl;
	}
	
	
	
	return 0;
}
