#include<bits/stdc++.h>
using namespace std;
int n,start,flag;
int m[100005];
bool pass[100005];
void dfs(int now)
{
	if(m[now]==0)
	{
		flag=1;
		return ;
	}
	if(pass[now])
	return ;
	if(now-m[now]>=0&&now-m[now]!=start)
	{
		pass[now]=1;
		dfs(now-m[now]);
		pass[now]=0;
	}
	if(now+m[now]<n&&now+m[now]!=start)
	{
		pass[now]=1;
		dfs(now+m[now]);
		pass[now]=0;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>m[i];
	cin>>start;
	dfs(start);
	if(flag==1)
	cout<<"True";
	else
	cout<<"False";
}
