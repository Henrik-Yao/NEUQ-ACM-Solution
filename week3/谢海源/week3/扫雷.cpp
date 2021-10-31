#include<bits/stdc++.h>
using namespace std;
const int fi[8]={-1, 0, 1, 0,-1,1,1,-1};//前四个为上下左右，后四个为斜着
const int fj[8]={0, -1, 0, 1,-1,1,-1,1};
bool lei[35][35];//记录是否有雷
int q[35][35];
int n,m,flag=0;//n行m列
void dfs(int i,int j)
{
	
	if(q[i][j]==-1&&lei[i][j]==0) q[i][j]=0;//打开
	else return;
	int xi,xj;
	for(int k=0;k<8;k++)//找周围有没有雷
	{
		xi=i+fi[k];
        xj=j+fj[k];
        if(xi<0||xi>=n||xj<0||xj>=m) continue;
        if(lei[i][j]==0&&lei[xi][xj]==1) q[i][j]++;//有雷
	}
	for(int k=0;k<8;k++)//移动
    {
        xi=i+fi[k];
        xj=j+fj[k];
        if(xi<0||xi>=n||xj<0||xj>=m) continue;//超界
        if(q[xi][xj]>=0||lei[xi][xj]==1) continue;//要开的位置已开过或有雷
        if(q[i][j]==0&&lei[i][j]==0) dfs(xi,xj);
    } 
}
void f()//输出和检验
{
	flag=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",q[i][j]);
			if(q[i][j]==-1&&lei[i][j]==0) flag=0;
		}
		printf("\n");
	}
}
int main()
{
	memset(q,-1,sizeof(q));
	memset(lei,0,sizeof(lei));
	int k,l;
	cin>>n>>m>>k>>l;
	int i,j;
	while(k--)
	{
		cin>>i>>j;
		lei[i][j]=1;
	}
	while(l--)
	{
		cin>>i>>j;
		if(lei[i][j]==1)//雷炸了0
		{
			cout<<"You lose\n";
			break;
		}
		else if(q[i][j]==-1)//有效点击
		{
			dfs(i,j);//点击i，j方格
	     	f();
	     	if(flag==1) printf("You win\n");
	     	else cout<<"\n";
		}
	}
	return 0;	
}
