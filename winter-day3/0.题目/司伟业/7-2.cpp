#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m,flag,t,ju[1005][1005],aa,bb,last;
struct node{
	int a,b,c;
}g[maxn];
bool cmp(node a,node b)
{
	if(a.a==b.a) return a.b<b.b;
	else return a.a<b.a;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>g[i].a>>g[i].b>>g[i].c;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>aa>>bb;
		ju[aa][bb]=1;
	}
	g[0].a=-1;
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(ju[g[i].a][g[i].b]) continue;
		if(g[i].a!=g[last].a)
		{
			if(flag==0)
			{
				flag=1;
				printf("%d:(%d,%d,%d)",g[i].a,g[i].a,g[i].b,g[i].c);
			}
			else printf("\n%d:(%d,%d,%d)",g[i].a,g[i].a,g[i].b,g[i].c);
		}
		else printf("(%d,%d,%d)",g[i].a,g[i].b,g[i].c);
		last=i;
	}
	return 0;
}
