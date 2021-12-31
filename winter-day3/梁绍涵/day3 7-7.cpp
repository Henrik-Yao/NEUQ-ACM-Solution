#include<bits/stdc++.h>
using namespace std;
int n,v,e;
int sum=0,ans=0;
struct Edge
{
	int from,to,val;
}edge[60];
int fa[60],vis[60],num=0;
int findf(int x)
{
	if(fa[x]==x)
	return x;
	else
	{
		return findf(fa[x]);
	}
}
int merge(int x1,int y1)
{
	int a = findf(x1);
    int b = findf(y1);
    if (a != b) {
        fa[b] = a;
        return 1;
    }
    return 0;
}
bool cmp(Edge a,Edge b)
{
	return a.val<b.val;
}
void Kruskal()
{
	for(int i=0;i<e;i++)
	{
		int x=edge[i].from;
		int y=edge[i].to;
		if((x==v||y==v)&&sum<2) 
		{
			if(merge(x,y))
			{
				ans+=edge[i].val;
				sum++;
				num++;
			}
		}
		else if(x!=v&&y!=v)
		{
			if(merge(x,y))
			{
				ans+=edge[i].val;
				num++;
			}
		}
        if (num == n - 1)
        break;   
	}
//	cout<<"x"<<num<<endl;
	if(num==n-1&&sum<=2)
        cout<<ans<<endl;
        else
        cout<<-1<<endl;
}
int main()
{
	while(cin>>n>>v>>e)
	{
		ans=0,sum=0,num=0;
		for(int i=0;i<n;i++)
		fa[i]=i;
		for(int i=0;i<e;i++)
		{
			cin>>edge[i].from>>edge[i].to>>edge[i].val; 
		}
		sort(edge,edge+e,cmp);
		Kruskal();
	}
	
}
