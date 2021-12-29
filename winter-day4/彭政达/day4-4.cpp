/*
7-4 最短路径之Floyd
请缩写程序，实现求有向网的最短路径的Floyd算法，因地点可能够是淡泊湖，宁静楼等等，
这里简化成编号，要求能够查询出任意两点（用编号表示）间的最短路径及最小距离。
说明：1）顶点个数上限不超过100；2）距离权值上限不超过9998；
输入样例:
第一行，两个整数：vN和eN（图中顶点数和和边数）。 接下来是vN条边的信息：
起点，终点，权值（三个数一行，以空格分隔）； 最后两行是待查询的两组起点与终点的编号
（每行一个查询，起点与终点编号间也是空格分隔）。
6 8
0 5 100
0 2 10
0 4 30
1 2 5
2 3 50
3 5 10
4 3 20
4 5 60
0 5
2 0
（三块信息：顶点数和边数；边的信息；两组需要查询的顶点信息） 
输出样例:
共输出三行，前两行分别输出两组查询的结果：先是起点到终点的路径说明，再是距离，
中间以冒号分隔。如果两个点间不可达，输出距离-1。最后一行是整个可达距离中最大距离的描述
(若有多组，输入位置稍前的一组，注意：不包括不可到达的无穷大)。
0->4->3->5:60
2->0:-1
1->2->3->5:65
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z,posx=-1,posy=-1,massimo;
int g[128][128],path[128][128];
int pre[128];
void effect(int x,int y){
	int k=path[x][y];
	if(k==-1){
		pre[y]=x;
		return;
	}
	effect(k,y);
	effect(x,k);
}
void print(int x,int y){
	if(x==y){
		cout<<x;
		return;
	}
	print(x,pre[y]);
	cout<<"->"<<y;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("in4.txt","r",stdin);
	memset(path,-1,sizeof(path));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		g[i][i]=0;
		for(int j=i+1;j<n;j++)
			g[i][j]=g[j][i]=32767;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(g[x][y]>z) g[x][y]=z;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				if(g[j][k]>g[j][i]+g[i][k]){
					g[j][k]=g[j][i]+g[i][k];
					path[j][k]=i;
				}
	for(int i=0;i<2;i++){
		cin>>x>>y;
		if(x==y) cout<<x<<"->"<<y<<":0"<<endl;
		else{
			if(g[x][y]==32767) cout<<x<<"->"<<y<<":-1"<<endl;
			else{
				memset(pre,0,sizeof(pre));
				effect(x,y);
				print(x,y);
				cout<<":"<<g[x][y]<<endl;
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mp[i][j]!=32767 && g[i][j]>massimo){
				massimo=g[i][j];
				posx=i;
				posy=j;
			}
	memset(pre,0,sizeof(pre));
	if(posx!=-1 && posy!=-1){
		effect(posx,posy);
		print(posx,posy);
		cout<<":"<<g[posx][posy];
	}
}
