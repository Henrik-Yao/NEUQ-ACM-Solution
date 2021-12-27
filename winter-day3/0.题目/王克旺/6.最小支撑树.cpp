#include<bits/stdc++.h>
using namespace std;
struct road{
    int from;
	int to;
	int cost;
}r[1500];
int pre[1500];
int find(int x)
{
    if(x==pre[x])
	{
		return x;
	}
    return pre[x]=find(pre[x]);
}
void Union(int u,int v)
{
    int x=find(u),y=find(v);
    if(x==y)
	{
		return;
	}
    pre[x]=y;
}
bool compair(road u,road v)
{
    return u.cost<v.cost;
}
int main()
{
    int n,e;
    while(cin>>n>>e)
    {
    	int count=0,sum=0;
		for(int i=0;i<n;i++)
   	    {
   		 	pre[i]=i;
		}
    	for(int i=0;i<e;i++)
    	{
    	    cin>>r[i].from>>r[i].to>>r[i].cost;
    	}
    	sort(r,r+e,compair);
    	for(int i=0;i<e;i++)
    	{
    	    if(find(r[i].from)!=find(r[i].to))
    	    {
    	        Union(r[i].from,r[i].to);
     	        count++;
    	       	sum+=r[i].cost;
    	    }
    	}
    	if(count<n-1)
    	{
    		cout<<"There is no minimum spanning tree."<<endl;
		}
		else
		{
			cout<<sum<<endl;
		}
	}	
    return 0;
}
