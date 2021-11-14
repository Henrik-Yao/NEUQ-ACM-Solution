#include<iostream>
#include<cstring>
using namespace std;

int sum = 0;
bool mount[2005][2005];
bool vis[2005][2005];

int dr[4] = { 0,1,0,-1 };//Y
int dc[4] = { 1,0,-1,0 };//X

void search(int i,int j) {
	if (vis[i][j]||!mount[i][j])return;
	vis[i][j] = 1;
	for (size_t m = 0; m < 4; m++)
	{
		search(i + dr[m], j + dc[m]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	memset(mount, 0, sizeof(mount));
	int m, n;
	cin >> m >> n;
	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			cin >> mount[i][j];
		}
	}
	memset(vis, 0, sizeof(vis));
	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			if (mount[i][j] && !vis[i][j]) {
				search(i, j); ++sum;
			}
		}
	}
	cout << sum << endl;
}
