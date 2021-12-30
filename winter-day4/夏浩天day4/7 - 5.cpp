//我的评价是，dfs
//摆！
//加一点记忆化思想
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;

string str(int n)
{
	return to_string(n);
}

int m, n;
int rx, ry, cx, cy;
int mg[10001][10001];
int arr[10001][10001];//到达此处消耗的最小能量
bool vis[10001][10001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string path = "";
void dfs(int x, int y,int xh,string o)
{
	if (vis[x][y])return;
	if (xh > arr[x][y])return;
	arr[x][y] = xh;
	if (x == cx && y == cy) { path = o; return; }
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i], xh+mg[x][y], "(" + str(x + dx[i]) + " " + str(y + dy[i]) + ")"+o);
	vis[x][y] = 0;
}

int main() 
{
	cin >> m >> n;
	cin >> rx >> ry >> cx >> cy;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> mg[i][j];
			arr[i][j] = 999999;
			if (mg[i][j] == -1)vis[i][j] = 1;
		}
	dfs(rx, ry, 0,"("+str(rx)+" "+str(ry)+")");
	cout << path;
}