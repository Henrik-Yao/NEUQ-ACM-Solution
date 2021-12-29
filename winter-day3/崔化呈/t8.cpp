#include<bits/stdc++.h>
using namespace std;
struct node
{
	int inn;
	int outn;
	int to[110];
}nd[110];
void init()
{
	for(int i=0;i<110;i++)
		{
			nd[i].inn=0;
			nd[i].outn=0;
			for(int j=0;j<110;j++)
			{
				nd[i].to[j]=0;
			}
		}
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		queue<node>q;
		for(int i=1;i<=m;i++)
		{
			int s,e;
			scanf("%d%d",&s,&e);
			nd[e].inn++;
			nd[s].outn++;
			nd[s].to[nd[s].outn]=e;
		}
		int snum=0;
		for(int i=1;i<=n;i++)
		{
			if(nd[i].inn==0){snum++;}
		}
		//cout<<snum<<endl;
		for(int i=1;i<=n;i++)
		{
			if(nd[i].inn==0)
			{
				if(i==n+1){printf("0\n");continue;}
				else{q.push(nd[i]);}
			}
		}
		int cnt=0;
		while(!q.empty())
		{
			cnt++;
			node te=q.front();
			q.pop();
			for(int j=1;j<=te.outn;j++)
			{
				nd[te.to[j]].inn--;
				if(nd[te.to[j]].inn==0){q.push(nd[te.to[j]]);}
			}
		}
		//cout<<cnt<<endl;
		if(cnt>=n&&snum>=2){printf("2\n");}
		else if(cnt>=n&&snum==1){printf("1\n");}
		else{printf("0\n");}
	}
}
