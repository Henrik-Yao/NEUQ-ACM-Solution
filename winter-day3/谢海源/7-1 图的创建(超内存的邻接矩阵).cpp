#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int g[maxn][maxn];
bool v[maxn]={};
//邻接矩阵创建图
int main()
{
	int n,e;
	cin>>n>>e;
	int a,b,c;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) g[i][j]=-1;
	}
	for(int i=0;i<e;i++)//e行
	{
		scanf("%d %d %d",&a,&b,&c);
		v[a]=1;
		g[a][b]=c;
	}
	for(int i=0;i<n;i++)//顶点
	{	
	    if(!v[i]) continue;
		cout<<i<<":";
		for(int j=0;j<n;j++)
		{
			if(g[i][j]>0) printf("(%d,%d,%d)",i,j,g[i][j]);
		}
		cout<<endl;
	}
    return 0;
}
