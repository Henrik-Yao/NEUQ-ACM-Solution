#include<bits/stdc++.h>
using namespace std;
int n,flag;
queue<int>q;
int in[100005],tot,m;
vector<int> a[100005];
int topo()
{
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			q.push(i);
		}
	}
	int tmp;
	while(!q.empty())
	{
		if(q.size()>1)flag=1;
		tmp=q.front();
		q.pop();
		tot++;
		for(int i=0;i<a[tmp].size();i++)
		{
			int y=a[tmp][i];
			in[y]--;
			if(in[y]==0)
			q.push(y);
		}
	}
	if(tot==n)
	{
		if(flag==1)
		cout<<"2"<<endl;
		else cout<<"1"<<endl;
	}
	else cout<<"0"<<endl;
}
int main()
{
	while(cin>>n>>m)
	{
		flag=0;
		tot=0;
		memset(in,0,sizeof(in));
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			in[y]++;
			a[x].push_back(y);
		}
		topo();
		for(int i=1;i<=n;i++)
			a[i].clear();
	}
}
