#include <bits/stdc++.h>
using namespace std;
int pre[20010];
struct edge
{
	int fr;
	int to;
	int w;
};
void init()
{
	for(int i=0;i<20010;i++)
	{
		pre[i]=i;
	}
}
bool cmp(edge e1,edge e2)
{
	return e1.w<e2.w;
}
int find(int x)
{
	int t=x;
	while(pre[t]!=t){t=pre[t];}
	return t;
}
bool join(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){pre[fy]=fx;return 1;}
	else{return 0;}
}
int main()
{
	int n,e;
	while(~scanf("%d%d",&n,&e))
	{
		//cout<<n<<' '<<e<<endl;
		edge ed[e];
		init();
		for(int i=0;i<e;i++)
		{
			scanf("%d%d%d",&ed[i].fr,&ed[i].to,&ed[i].w);
		}
		sort(ed,ed+e,cmp);
		int cnt=0,wsum=0;
		for(int i=0;i<e;i++)
		{
			if(join(ed[i].fr,ed[i].to))
			{
				cnt++;
				wsum+=ed[i].w;
			}
			if(cnt==n-1){break;}
		}
		if(cnt==n-1){cout<<wsum<<endl;}
		else{cout<<"There is no minimum spanning tree."<<endl;}
	}
	return 0;
}
