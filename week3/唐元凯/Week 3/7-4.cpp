#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, nextx, nexty;
int sum=0,t=0;
char map[1005][1005];
int vis[1005][1005];
int result[1005*1005];

const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };

void mova(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > n)return;
	if (vis[x][y])return;
	vis[x][y] = t;
	++sum;
	for (int i = 0; i < 4; i++)
	{
		nextx = x + dc[i]; 
		nexty = y + dr[i];
		if (map[x][y]!=map[nextx][nexty]) {
			mova(nextx, nexty);
		}
	}
	result[t] = sum;
}

int main() {
	ios::sync_with_stdio(false);
	memset(map, 0, sizeof(map));
	cin >> n >> m;
	//input map
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n ; j++)
		{
			cin >> map[i][j];
		}
	}
	//input start && loop
	int x, y;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (!vis[x][y]) {
			++t;
			sum = 0;
			mova(x, y);
		}
		cout << result[vis[x][y]] << '\n';
	}
}