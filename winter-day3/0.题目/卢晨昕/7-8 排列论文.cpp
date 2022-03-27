#include<bits/stdc++.h>

using namespace std;
int n,m;
struct node
{
	int nex,to,pre;
}e[105];
int head[105];
int cnt;
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
int in[105];
int inzero;
int main()
{
	while(cin>>n>>m)
	{
		int flag=0;
		int ans=0;
		cnt=0;
		memset(head,0,sizeof(head));
		memset(in,0,sizeof(in));
		for(int i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
			add(b,a);
			in[a]++;
		}
		queue<int>q;
		for(int i=1;i<=n;i++)
		{
			if(in[i]==0)q.push(i);
		}
		while(!q.empty())
		{
			if(q.size()>1)
			{
				flag=1;
			}
			int x=q.front();
			q.pop();
			for(int i=head[x];i;i=e[i].nex)
			{
				int y=e[i].to;
				in[y]--;
				if(in[y]==0)q.push(y);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(in[i]!=0)ans=1;//ÓÐ»· 
		}
		if(ans==0)
		{
			if(flag==1)cout<<2<<endl;
			else cout<<1<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
