#include<bits/stdc++.h>
using namespace std;
int pre[55];
struct road
{
	int fr;
	int to;
	int v;
}ro[55];
bool cmp(road r1,road r2)
{
	return r1.v<r2.v;
}
void init()
{
	for(int i=0;i<55;i++)
	{
		pre[i]=i;
	}
}
int find(int x)
{
	while(x!=pre[x])
	{
		x=pre[x];
	}
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
	int n,v,e;
	while(~scanf("%d%d%d",&n,&v,&e))
	{
		for(int i=0;i<e;i++)
		{
			scanf("%d%d%d",&ro[i].fr,&ro[i].to,&ro[i].v);
		}
		sort(ro,ro+e,cmp);
		init();	
		int cnt=0,maxx=0,vsum=0;
		for(int i=0;i<e;i++)
		{
			if((ro[i].fr==v||ro[i].to==v)&&maxx<2)
			{
				if(link(ro[i].fr,ro[i].to))
				{
					cnt++;maxx++;vsum+=ro[i].v;
				}
			}
			else if(ro[i].fr!=v&&ro[i].to!=v)
			{
				if(link(ro[i].fr,ro[i].to))
				{
					cnt++;vsum+=ro[i].v;
				}
			}
			else{}
			if(cnt==n-1){break;}
		}
		//cout<<maxx<<endl;
		if(cnt==n-1&&maxx<=2){cout<<vsum<<endl;}
		else{cout<<-1<<endl;}
	}
	
	return 0;
}
