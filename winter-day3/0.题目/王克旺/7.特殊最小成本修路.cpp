#include<bits/stdc++.h>
using namespace std;
struct road{
    int from;
	int to;
	int cost;
}r[50];
int pre[50];
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
    int n,v,e;
    while(cin>>n>>v>>e)
    {
    	int count=0,sum=0,num=0;
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
    		if((r[i].from==v||r[i].to==v)&&num<2)
    		{
    			if(find(r[i].from)!=find(r[i].to))
    	        {
    	            Union(r[i].from,r[i].to);
     	            count++;
    	       	    sum+=r[i].cost;
    	       	    num++;
    	        }
			}
    	    else if(r[i].from!=v&&r[i].to!=v)
    	    {
    	    	if(find(r[i].from)!=find(r[i].to))
    	        {
    	            Union(r[i].from,r[i].to);
     	            count++;
    	       	    sum+=r[i].cost;
    	        }
			}
    	}
    	if(count==n-1&&num<=2)
    	{
    		cout<<sum<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}	
    return 0;
}
