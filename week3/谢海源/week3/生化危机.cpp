#include<bits/stdc++.h>
using namespace std;
bool a[101];//是否安全
bool s[101];//标记已经遍历过的城市
vector<int>link[101];//存连接的的城市编号
bool f;
void dfs(int x,int y)
{
	int i;
	for(auto i:link[x])//遍历x连接的城市    
	{
		if(i==y)
		{
			f=1;
			return;
		}
		else if(s[i]==0)
		{
			s[i]=1;
		    dfs(i,y);
		    s[i]=0;//遍历后退回来
		}
	}
	return;
}
int main()
{
	memset(a,0,sizeof(a));//初始化
	memset(s,0,sizeof(s));//初始化
	int m,n,k,t;
	cin>>m>>n>>k;
	while(n--)//标记安全城市
	{
		cin>>t;
		a[t]=1;
	}
	int x,y;
	while(k--)//连接两个城市
	{
		cin>>x>>y;
		link[x].push_back(y);
		link[y].push_back(x);
	}
	cin>>x>>y;//从x要到y
	if(a[y]==0) printf("The city %d is not safe!",y);
	else//目标安全
	{
		f=0;
		dfs(x,y);
		if(f==1) printf("The city %d can arrive safely!",y);
		else if(f==0) printf("The city %d can not arrive safely!",y);
	}
	return 0;	
}
