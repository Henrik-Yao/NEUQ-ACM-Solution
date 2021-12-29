#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Edge
{
	int form,to;
}edge[300];

int rud[300];
int main()
{
	while(cin>>n>>m)
	{
		int many=0,s=0,flag=0;
		int vis[300];
		vector<int> G[300];
		queue<int> q;
		memset(vis,0,sizeof(vis));
		memset(rud,0,sizeof(rud));
		memset(edge,0,sizeof(edge));
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			rud[v]++;
			G[u].push_back(v);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(rud[i]==0)
			{
				s++;
				flag=1;
				q.push(i);
			}
		}
		if(flag==0)
		{
			cout<<0<<endl;
			continue;
		}
		if(s>=2) many=1;
		
			while(!q.empty())
		{
			s=0;
			int now;
			now=q.front();
			q.pop();
//			cout<<now<<"x"<<endl;
			for(int i=0;i<G[now].size();i++)
			{
				int v=G[now][i];
				rud[v]--;
				if(rud[v]==0)
				{
					s++;
//					if(s>=2) cout<<"xxx"<<now<<" "<<v<<endl;
					q.push(v);
				}
			}
			
			if(s>=2)
			{
				many=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(rud[i]!=0)
			flag=0;
		}
		if(flag==0)
		cout<<0<<endl;
		else
		{
			if(many==1)
			cout<<2<<endl;
			else
			cout<<1<<endl;
		}
	}
	
}
