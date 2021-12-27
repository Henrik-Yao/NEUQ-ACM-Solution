#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 100 + 5;
int x, y;
int pic[maxn][maxn],idx[maxn][maxn];

const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };

void dfs(int r, int c, int id) {
	if (r<1 || r>x || c<1 || c>y) return;
	if (idx[r][c] > 0 || pic[r][c] != 1)return;
	idx[r][c] = id;
	for(int i=0;i<4;i++)
		dfs(r + dr[i], c + dc[i], id);
}

int main() {
	memset(idx, 0, sizeof(idx));
	memset(pic, -1, sizeof(pic));
	cin >> x>> y;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++) cin >> pic[i][j];
	int cnt = 0;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
			if (idx[i][j] == 0 && pic[i][j] == 1)dfs(i, j, ++cnt);
	cout << cnt;
}