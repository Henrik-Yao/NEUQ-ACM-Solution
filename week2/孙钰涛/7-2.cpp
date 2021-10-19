#include <bits/stdc++.h>
using namespace std;

struct pass
{
	int a;
	int b;
}citypass[10001];

int main()
{
	int n,m,num[10001];
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>citypass[i].a>>citypass[i].b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int flag=0,N,x;
		memset(num,0,sizeof(num));
		cin>>N;
		for(int j=1;j<=N;j++)
		{
			cin>>x;
			num[x]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(num[citypass[j].a]==0 && num[citypass[j].b]==0)
			{
				flag=1;
			}
		}


		if(flag==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}