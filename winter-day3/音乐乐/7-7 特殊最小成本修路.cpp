#include<bits/stdc++.h>
using namespace std;
int F[51];
struct Edge
{
	int from;
	int to;
	int w;
}edge[51];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(F[x]==x)
	return F[x];
	else
	return F[x]=find(F[x]);
}
bool fun(int a,int b)
{
	int x=find(a);
	int y=find(b);
	//cout<<"x"<<x<<' '<<"y"<<y<<' '<<endl;
	if(x!=y)
	{
		F[y]=x;
		return true;
	}
	return false;
}
int main()
{
	int n,e,v,i;
	while(~scanf("%d%d%d",&n,&v,&e))
	{
		int total=0,cnt=0,num=0;
		for(i=0;i<e;i++)
		{
			scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
		}
		for(i=0;i<n;i++)
			F[i]=i;
		sort(edge,edge+e,cmp);
		for(i=0;i<e;i++)
		{
			if((edge[i].from==v||edge[i].to==v)&&cnt<2)
			{
				if(fun(edge[i].from,edge[i].to))
				{
					total+=edge[i].w;
					cnt++;
					num++;
				}
			}
			else if(edge[i].from!=v&&edge[i].to!=v)
			{
				if(fun(edge[i].from,edge[i].to))
				{
					total+=edge[i].w;
					num++;
				}
			}
			 if (num == n - 1)
                break;
		}
		if (num==n - 1 && cnt <= 2)
        printf("%d\n", total);
        else
        printf("-1\n");
	}
	return 0;
}

