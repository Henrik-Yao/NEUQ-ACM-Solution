#include<string.h>
#include<iostream>
using namespace std;
int dir[4][2] = { {0,1}, {-1,0}, {1,0},{0,-1} };  
char map[1001][1001]; 
bool vis[1001][1001]; 
int root[1001][1001], w[1000001];  
int cnt=0; 
int n, m, tx[100001], ty[100001];  
void solve(int x, int y)
{
	if(!vis[x][y]){
		vis[x][y] = true;
		cnt++; 	
		root[x][y] = cnt;
		w[cnt]++;
	}
	for(int k = 0; k < 4; k++){
		int nx = x + dir[k][1], ny = y + dir[k][0]; 
		if(nx>=1 && nx<=n && ny>=1 && ny<=n && !vis[nx][ny] && map[x][y]!=map[nx][ny]){
			vis[nx][ny] = true;
			root[nx][ny] = cnt; 
			w[cnt]++; 	    
			solve(nx, ny);
		}
	}
}
int main()
{
	memset(w, 0, sizeof(w)); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> map[i][j]; 
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++)
			solve(i, j);      
	for(int i = 1; i <= m; i++) cin >> tx[i] >> ty[i]; 
	for(int i = 1; i <= m; i++) cout << w[root[tx[i]][ty[i]]] << endl; 
	return 0;
}//from luogu

