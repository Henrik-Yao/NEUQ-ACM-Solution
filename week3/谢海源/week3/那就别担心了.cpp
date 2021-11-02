#include<bits/stdc++.h>
using namespace std;
bool x[510];//标记已经遍历过的
int s[510],sum[510];//s为逻辑自洽数，sum为推理总路数
vector<int>infer[510];
void dfs(int a,int b)
{
	x[a]=1;//标记走过的点
	int i;
	if(infer[a].empty()||a==b)//容器为空推理到头了或到达b
	{
		if(a==b) s[a]=1;
		sum[a]=1;
		return;
	}
	for(auto i:infer[a])//遍历x连接的命题
	{
		if(x[i]==0)
		{
			dfs(i,b);
		}
		s[a]+=s[i];
		sum[a]+=sum[i];
	}
	return;
}
int main()
{
	memset(x,0,sizeof(x));//初始化
	memset(s,0,sizeof(s));//初始化
	memset(sum,0,sizeof(sum));//初始化
	int n,m,a,b;
	cin>>n>>m;
	while(m--)
	{
		scanf("%d %d",&a,&b);
		infer[a].push_back(b);//a能推出b
	}
	scanf("%d %d",&a,&b);//从a推到b
	dfs(a,b);
    if(s[a]==sum[a])printf("%d Yes\n",s[a]);
	else printf("%d No\n",s[a]);
	return 0;	
}
