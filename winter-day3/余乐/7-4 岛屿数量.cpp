#include <cstdio>
#define N 101
using namespace std;

int n,m,ans,map[N][N];

void solve(int x,int y){
	if(x < 0 || y < 0 || x > n || y > m || map[x][y] == 0) return;
	map[x][y] = 0;
	solve(x - 1 , y);
	solve(x + 1 , y);
	solve(x , y - 1);
	solve(x , y + 1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			scanf("%d",&map[i][j]);
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			if(map[i][j]){
				ans ++;
				solve(i , j);
			}
	printf("%d",ans);
	return 0;
}
