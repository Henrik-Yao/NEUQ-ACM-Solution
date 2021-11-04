#include<bits/stdc++.h>
using namespace std;
#define mm 10000000
int head[mm],now[mm],pass[mm];
int num=0,n,m,endd,result,flag;
struct node
{
	int from;
	int to;
	int next;
}edge[501];
void add(int from,int to)
{
	num++;
	edge[num].to=to;
	edge[num].next=head[from];
	head[from]=num;
}
void dfs(int start)
{
	if(start==endd)
	return ;
	for(int i=head[start];i;i=edge[i].next)
	{
		int t=edge[i].to; 
		if(pass[t]==0)
		{
			pass[t]=1;
			dfs(t);
			pass[t]=0;
		}
		now[start]+=now[t];
	}
	if(now[start]==0)
	flag=1;
}
int main()
{
	int start;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int p,q;
		cin>>p>>q;
		add(p,q);
	}
	cin>>start>>endd;
	now[endd]=1;
	pass[start]=1;
	dfs(start);
	if(flag==1)
	cout<<now[start]<<" "<<"No";
	else
	cout<<now[start]<<" "<<"Yes";
}

