#include<bits/stdc++.h>
using namespace std;
int fa[1010];
int find(int x)
{
	if(fa[x]==x){return x;}
	return fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
	int fax=find(x);
	int fay=find(y);
	if(fax==fay){return;}
	fa[fax]=fay;
	return;
}
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		unionn(a,b);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		if(find(a)==find(b)){cout<<"In the same gang."<<endl;}
		else{cout<<"In different gangs."<<endl;}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(find(i)==i){ans++;}  //tou mu
	}
	cout<<ans<<endl;
	return 0;
}
