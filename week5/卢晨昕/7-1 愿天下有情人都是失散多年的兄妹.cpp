#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int k;
map<int,char>sex;
int vis[1000005];
bool ans;

struct node
{
	int to,nex;
}e[1000005];
int head[1000005];
int cnt;

void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].nex=head[a];
	head[a]=cnt;
}

void dfs(int a,int num)
{
	if(ans==false)return;
	if(num>=4)return;
	for(int i=head[a];i;i=e[i].nex)
	{
		int y=e[i].to;
		if(!vis[y])
		{
			vis[y]=1;
			dfs(y,num+1);
		}
		else ans=false;
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char sexx;
		int faa,maa,id;
		cin>>id>>sexx>>faa>>maa;
		sex[id]=sexx;
		if(faa!=-1)
		{
			sex[faa]='M';
			add(id,faa);
		}
		if(maa!=-1)
		{
			sex[maa]='F';
			add(id,maa);
		}
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		if(sex[a]==sex[b])
		{
			if(i!=k)cout<<"Never Mind"<<endl;
			else cout<<"Never Mind";
		}
		else
		{
			memset(vis,0,sizeof(vis));
			ans=true;
			dfs(a,0);
			dfs(b,0);
			if(ans==false)
			{
				if(i!=k)cout<<"No"<<endl;
			    else cout<<"No";
			}
			else
			{
				if(i!=k)cout<<"Yes"<<endl;
			    else cout<<"Yes";
			}
		}
	}
	return 0;
}
