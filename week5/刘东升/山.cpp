#include<bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,1,0};//���������ƶ���������ʽ 
const int dy[4]={0,-1,0,1};
int m,n,ans=0,fx,fy;
void dfs(int x,int y); 
const int M=2001;
bool mou[M][M];//��ͼ 
bool judge[M][M];//�ж� 
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mou[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mou[i][j]==0||judge[i][j]==1) continue;//�����ƽ�ػ����Ѿ������������ 
			dfs(i,j);//��ʼ����������ɽ 
			ans++;//ɽ�Ĵ𰸼�һ 
		}
	}
	cout<<ans;
}
void dfs(int x,int y)
{
	judge[x][y]=1;//��Ǵ�ɽ�ĵط� 
	for(int i=0;i<4;i++)//Ѱ�������ƶ����� 
	{
		fx=dx[i]+x;//�ƶ� 
		fy=dy[i]+y;
		if(fx<1||fx>m||fy<1||fy>n) continue;//�����˱߽������� 
		if(judge[fx][fy]==1||mou[fx][fy]==0) continue;//����ǿյػ����Ѿ������������ 
		dfs(fx,fy);//�������� 
	}
}
