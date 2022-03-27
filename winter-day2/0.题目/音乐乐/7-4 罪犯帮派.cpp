#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int f[100010];
int find(int x)
{
	if(f[x]==x)
	return x;
	else
	return f[x]=find(f[x]);
}

int main()
{
	cin>>n>>m>>q;
	int a,b,x,y;
	int ans=n-m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	while(m--)
	{
		cin>>a>>b;
		x=find(a);
		y=find(b);
		if(x!=y) f[x]=y;
	}
	while(q--)
	{
		cin>>x>>y;
		if(find(x)!=find(y))
			cout<<"In different gangs."<<endl;
		else
			cout<<"In the same gang."<<endl;
	}
	cout<<ans;
	return 0;
}
