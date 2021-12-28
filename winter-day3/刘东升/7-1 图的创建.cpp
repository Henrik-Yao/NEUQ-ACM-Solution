#include<bits/stdc++.h> 
using namespace std;
vector<int>v[20010];
int m,temp[20010],mem[20010];
struct edge
{
	int to;
	int next;
	int w;
}e[20010];
void add(int x,int y,int z); 
int main()
{
	int n,t,i;
	cin>>n>>t;
	for(i=1;i<=t;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(i=0;i<n;i++)
	{
		memset(temp,0,sizeof(temp));
		memset(mem,0,sizeof(mem));
		if(v[i].size())
		{
			int cap=v[i].size();
			for(int j=0;j<cap;j++)
			{
				temp[j]=e[v[i][j]].to;
				mem[temp[j]]=e[v[i][j]].w;
			}
			sort(temp,temp+cap);
			cout<<i<<':';
			for(int j=0;j<cap;j++)
			{
				cout<<"("<<i<<","<<temp[j]<<","<<mem[temp[j]]<<")";
			} 
			cout<<endl;
		}
	}
}
void add(int x,int y,int z)
{
	++m;
	v[x].push_back(m);
	e[m].to=y;
	e[m].next=x;
	e[m].w=z;
}
