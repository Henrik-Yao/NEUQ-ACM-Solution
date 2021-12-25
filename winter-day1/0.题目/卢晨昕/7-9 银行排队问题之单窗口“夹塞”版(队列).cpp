#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
map<string,int>mmp;//属于那个圈子
struct node
{
	string name;
	int t,p;
}nodes[100005];
bool vis[100005];
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int l;
		cin>>l;
		for(int j=0;j<l;j++)
		{
			string name;
			cin>>name;
			mmp[name]=i+1;
		}
	}
	int tot=m+1;
	for(int i=0;i<n;i++)
	{
		cin>>nodes[i].name>>nodes[i].t>>nodes[i].p;
		if(!mmp[nodes[i].name])mmp[nodes[i].name]=tot++;
		if(nodes[i].p>60)nodes[i].p=60;
	}
	int ans=0;//等待时间 
	int time=nodes[0].t+nodes[0].p;//总用时 
	queue<node>q;
	q.push(nodes[0]);
	vis[0]=true;
	while(!q.empty())
	{
		node now=q.front();
		cout<<now.name<<endl;
		q.pop();
		bool flag=false;
		for(int i=1;i<n;i++)//寻找有无朋友 
		{
			if(vis[i])continue;
			if(nodes[i].t>time)break;
			if(mmp[nodes[i].name]==mmp[now.name])//有 
			{
				q.push(nodes[i]);
				vis[i]=true;
				flag=true;
				ans+=time-nodes[i].t;//加上该朋友等待的时间 
				time+=nodes[i].p;//结束时间加上朋友用的时间 
				break;
			}
		}
		if(!flag)//无朋友
		{
			for(int i=1;i<n;i++)//寻找下一个人 
			{
				if(vis[i])continue;
				q.push(nodes[i]);
				vis[i]=true;
				ans+=max(0,time-nodes[i].t);//加上该人的等待时间 
				if(nodes[i].t>time)time=nodes[i].t;//用该人所用的时间更新总用时 
				time+=nodes[i].p;
				break;
			}
		}
	}
	printf("%0.1lf",1.0*ans/n);
	return 0;
}
