#include<bits/stdc++.h>
#define ll long long
using namespace std;
int fa[1000000];
int n,m,q;int tot;
bool vis[100000];
int get(int x)
{
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);//Â·¾¶Ñ¹Ëõ 
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		merge(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[get(i)])vis[fa[i]]=1,tot++;
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		if(fa[x]==fa[y])
		cout<<"In the same gang."<<endl;
		else cout<<"In different gangs."<<endl;
	}
	cout<<tot;
	return 0;
}
