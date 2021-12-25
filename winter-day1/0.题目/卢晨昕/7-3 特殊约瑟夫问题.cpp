#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int len,m,k;
int now=1;
int jia=-1;
int v[1005];
bool check()
{
	for(int i=1;i<=len;i++)
	{
		if(v[i]==0)return false;
	}
	return true;
}
int main()
{
	cin>>len>>m>>k;
	while(1)
	{
		if(check())break;
		if(jia==-1)
		{
			for(int i=1;i<m;i++)
			{
				now+=jia;
				if(now==0)now=len;
				while(1)
				{
					if(v[now]==1)
					{
						now+=jia;
						if(now==0)now=len;
					}
					else break;
				}
			}
			cout<<now<<" ";
			v[now]=1;
			jia=-jia;
		}
		else if(jia==1)
		{
			for(int i=1;i<k;i++)
			{
				now+=jia;
				if(now==len+1)now=1;
				while(1)
				{
					if(v[now]==1)
					{
						now+=jia;
						if(now==len+1)now=1;
					}
					else break;
				}
			}
			cout<<now<<" ";
			v[now]=1;
			jia=-jia;
		}
	}
	return 0;
}
