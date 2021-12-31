#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int pre[maxn],vis[maxn]={0};

int find(int x)
{
	if(pre[x]==x) return x;
	else return find(pre[x]);
}
int main()
{
	int m,n,q,i,l=0,a,b;
	cin>>n>>m>>q;
	for(i=0;i<n;i++)	pre[i]=i;	
	while(m--)
	{
		cin>>a>>b;
		if(pre[a]==a && pre[b]==b)	pre[a]=b; 
		else if(pre[a]!=a && pre[b]==b)	pre[b]=find(a);
		else if(pre[b]!=b && pre[a]==a)	pre[a]=find(b);
		else 
		{
			if(find(a)!=find(b))	pre[find(a)]=find(b);
		}
		
	}
	while(q--)
	{
		cin>>a>>b;
		if(find(a)==find(b)) cout<<"In the same gang.";
		else cout<<"In different gangs.";
		cout<<endl;
	}
	for(i=0;i<n;i++)	if(pre[i]==i) l++;
	cout<<l<<endl;
	return 0;
}
