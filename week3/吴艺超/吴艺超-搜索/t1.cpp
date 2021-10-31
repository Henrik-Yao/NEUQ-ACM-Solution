#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int m,n,k,head[105],tot;
bool an[105],vis[105];
int flag,s,d;
struct ax{
	int net,to;
}a[105];
queue<int> q;
void add(int net,int to)
{
	a[++tot].to=to;
	a[tot].net=head[net];
	head[net]=tot;
}
void dfs()
{
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();vis[x]=0;
		for(int i=head[x];i;i=a[i].net)
		{
			int to=a[i].to;
			if(an[to]==1)
			{
				if(to==d)
				{
					flag=1;
					printf("The city %d can arrive safely!",d);
					return;
				}
				if(!vis[to])q.push(to),vis[to]=1;
			}
		}
	}
}
int main()
{
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		an[x]=1;
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	cin>>s>>d;
//	an[s]=1;
	if(an[d]==0)
	{
		printf("The city %d is not safe!",d);
		return 0;
	}
	dfs();
	if(flag==0)
	{
		printf("The city %d can not arrive safely!",d);
		return 0;
	}
	return 0;
}
//The city 1 is not safe!
//The city 3 can not arrive safely!
