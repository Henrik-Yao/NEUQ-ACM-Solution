#include <bits/stdc++.h>
using namespace std;
int pre[31000];
void init()
{
	for(int i=0;i<31000;i++)
	{
		pre[i]=i;
	}
}
struct edge
{
	int fr;
	int to;
	int w;
};
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	while(x!=pre[x]){x=pre[x];}
	return x;
}
bool link(int x,int y)
{
	int fax=find(x);
	int fay=find(y);
	if(fax!=fay){pre[fax]=fay;return 1;}
	else{return 0;}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	edge ed[15500];
	init();
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&ed[i].fr,&ed[i].to,&ed[i].w);
	}
	sort(ed,ed+m,cmp);
	int s=0,maxx;
	for(int i=0;i<m;i++)
	{
		if(link(ed[i].fr,ed[i].to))
		{
			s++;
			maxx=ed[i].w;
		}
		if(s==n-1){break;}
	}
	printf("%d %d",s,maxx);
	return 0;
}
