#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[105];
int v[105];
int ans,num;
int len[105];
int que[105][105];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)return false;
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(1)
	{
		len[++ans]=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]==0)
			{
				if(len[ans]==0)
				{
					que[ans][++len[ans]]=a[i];
					if(a[i]==1)num=ans;
					v[i]=1;
				}
				else if(a[i]<que[ans][len[ans]])
				{
					que[ans][++len[ans]]=a[i];
					if(a[i]==1)num=ans;
					v[i]=1;
				}
			}
		}
		if(check())break;
	}
	for(int i=1;i<len[num];i++)
	{
		cout<<que[num][i]<<" ";
	}cout<<que[num][len[num]]<<endl;
	cout<<ans;
	return 0;
}
