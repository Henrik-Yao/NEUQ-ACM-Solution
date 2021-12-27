#include <bits/stdc++.h>
using namespace std;
int n,m,q,fa[10001],ans,a,b,c,d;
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	else return fa[x]=find(fa[x]);
}
void marge(int x,int y)
{
	fa[find(x)]=find(y);
}
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		marge(a,b);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>c>>d;
		if(find(c)==find(d))
		{
			cout<<"In the same gang."<<endl;
		}
		else cout<<"In different gangs."<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
