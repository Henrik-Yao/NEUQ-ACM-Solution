#include<bits/stdc++.h>
using namespace std;
int sn=0;//帮派数量
vector<int>group[1005];
int num[1005]={};
void getgroup(int a,int b)
{
	for(int i=1;i<=sn;i++)
		{
			for(auto&k:group[i])
			{
				if(k==a)
				{
					num[b]=i;
					group[i].push_back(b);
					return;
				}
				else if(k==b)
				{
					num[a]=i;
					group[i].push_back(a);
					return;
				}
			}
		}
	sn++;//若未有符合帮派则创建
	num[a]=sn;
	num[b]=sn;
	group[sn].push_back(a);
	group[sn].push_back(b);
}
void match(int a,int b)
{
	
}
int main()
{	
	int n,m,q;
	cin>>n>>m>>q;
	int a,b;
	while(m--)
	{
		cin>>a>>b;
		getgroup(a,b);
	}
	while(q--)
	{
		cin>>a>>b;
		if(num[a]==num[b]&&num[a]!=0) cout<<"In the same gang."<<endl;
		else cout<<"In different gangs."<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(!num[i]) sn++;
	}
	cout<<sn<<endl;
	return 0;
}
