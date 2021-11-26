#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#define maxn 2000005
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

struct node
{
	int vis,hash;
	string key;
};
int n,part[10];
char opt;
string name,key;
map<string,node>q;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>opt;
		if(opt=='R')//resign
		{
			cin>>name>>key;
			if(q[name].vis==1) puts("Repeated!");
			else
			{
				q[name].key=key;
				puts("Signed!");
				q[name].vis=1;
				int lenth=key.size();
				for(int j=0;j<lenth;j++)
					if(key[j]>='A'&&key[j]<='Z')
					key[j]+=32;
				for(int j=1;j<=4;j++) part[j]=lenth/4;
				for(int j=1;j<=(lenth%4);j++) part[j]++;
				int u=0,ans=0;
				for(int j=1;j<=4;j++)
				{
					int num=0;
					for(int l=0;l<part[j];l++,u++)
					{
						if(key[u]>='0'&&key[u]<='9') num+=key[u]-'0';
						else num+=key[u]-'a'+10;
					}
					ans+=(num%36)*(int)pow(36,4-j);
				}
				q[name].hash=ans;
			}
		}
		if(opt=='L')//log in
		{
			cin>>name>>key;string aaa=key;
			int lenth=key.size();
			for(int j=0;j<lenth;j++)
				if(key[j]>='A'&&key[j]<='Z')
				key[j]+=32;
			for(int j=1;j<=4;j++) part[j]=lenth/4;
			for(int j=1;j<=(lenth%4);j++) part[j]++;
			int u=0,ans=0;
			for(int j=1;j<=4;j++)
			{
				int num=0;
				for(int l=0;l<part[j];l++,u++)
				{
					if(key[u]>='0'&&key[u]<='9') num+=key[u]-'0';
					else num+=key[u]-'a'+10;
				}
				ans+=(num%36)*(int)pow(36,4-j);
			}
			if(q[name].vis==1&&q[name].key==aaa) puts("Success!");
			else if(q[name].vis==1&&q[name].key!=key&&q[name].hash==ans) puts("Attention!");
			else puts("Failed!");
		}
	}
	return 0;
}
