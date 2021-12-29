#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define inf 65535

int point[maxn][2];//存储搜到的点
int path[maxn][2];//存储最短路径上的点
int mp[1001][1001];//存图
int ans[1001][1001];//总能量消耗
int walk[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int m,n,stax,stay,endx,endy,cnt,cnt_ans;//cnt是当前搜到的点的数量，cnt_ans是最短路径上点的数量
void dfs(int u,int v){
	if(u == endx && v == endy){//如果到达终点
		for(int i = 0;i < cnt;i++){
			path[i][0] = point[i][0];
			path[i][1] = point[i][1];
			cnt_ans = cnt;
		}
		return;
	}
	for(int k = 0;k < 4;k++){
		int xx = u + walk[k][0];
		int yy = v + walk[k][1];
		if(xx < 1 || xx > m || yy < 1 || yy > n || mp[xx][yy] == -1 || ans[xx][yy] <= ans[u][v] + mp[xx][yy])continue;
		point[cnt][0] = xx,point[cnt][1] = yy;
		ans[xx][yy] = ans[u][v] + mp[xx][yy];
		cnt++;
		dfs(xx,yy);
		cnt--;//回溯
	}
}
int main(){
	scanf("%d%d",&m,&n);
	scanf("%d%d%d%d",&stax,&stay,&endx,&endy);
	for(int i = 0;i < m;i++){//建图
		for(int j = 0;j < n;j++){
	int data;
	scanf("%d",&data);
	mp[i][j] = data;
	}}
	for(int i = 1;i <= m - 2;i++)
		for(int j = 1;j <= n - 2;j++)
			ans[i][j] = inf;
	ans[stax][stay] = mp[stax][stay];
	point[cnt][0] = stax,point[cnt][1] = stay;
	cnt++;
	dfs(stax,stay);
	for(int i = cnt_ans - 1;i >= 0;i--){//逆序输出
		printf("(%d %d)",path[i][0],path[i][1]);
	}
	puts("");
	return 0;
}
