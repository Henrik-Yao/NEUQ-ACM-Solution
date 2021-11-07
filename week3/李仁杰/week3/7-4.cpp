#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<map>
using namespace std;
#define MAXSIZE 1001

char ma[MAXSIZE][MAXSIZE];
bool visit[MAXSIZE][MAXSIZE];
int root[MAXSIZE][MAXSIZE], w[1000001];
int n, m, tx[100001], ty[100001], connect = 0;
int dir[4][2] = { {0,1}, {-1,0}, {1,0},{0,-1} };

void search(int x, int y)
{
	if (!visit[x][y]) {
		connect++;
		visit[x][y] = true;
		root[x][y] = connect;
		w[connect]++;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x + dir[k][1], ny = y + dir[k][0];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visit[nx][ny] && ma[x][y] != ma[nx][ny]) {
			root[nx][ny] = connect; 
			visit[nx][ny] = true;
			w[connect]++;
			search(nx, ny);
		}
	}
}
int main()
{
	memset(w, 0, sizeof(w));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ma[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			search(i, j);
		}
	}
	for (int i = 1; i <= m; i++) cin >> tx[i] >> ty[i];
	for (int i = 1; i <= m; i++) cout << w[root[tx[i]][ty[i]]] << endl;
	return 0;
}