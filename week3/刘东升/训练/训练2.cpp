#include<bits/stdc++.h>
using namespace std;
const int M=500; 
int n,m,judge[M][M],vis[M],flag=1,a[M],u,v,answer=0;
int dfs(int u);
int main()
{
	cin>>n>>m;
	memset(judge,0,sizeof(judge));//���һ�� 
	for(int i=1;i<=m;i++)//������� 
	{
		int u,v;
		cin>>u>>v;
		judge[u][v]=1;
	}
	cin>>u>>v;
	a[v]=1;//���b 
	answer=dfs(u);
	cout<<answer;
	if(flag==0) 
	{
		cout<<" No";//��flag�ж� 
	} 
	else
	{
		cout<<" Yes";
	} 
}
int dfs(int u)
{
	if(a[u])//�յ������غ�ʱ 
	{
		return a[u];
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(judge[u][i]==0)//δ����������� 
		{
			continue; 
		} 
		if(a[i]);
		else 
		dfs(i);
		res+=a[i];
	}
	if(res==0)//���û�����ʾ���ܼ�no 
	flag=0;
	return a[u]=res;
}
