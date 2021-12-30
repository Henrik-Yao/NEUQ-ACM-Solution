#include<bits/stdc++.h>
using namespace std;
int n, v, e, f[55];
struct edge
{
	int a, z, w;
};

bool cmp(edge e1, edge e2)
{
	return e1.w<e2.w;
}
int find(int x)
{
    if(f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}
int merge(int x,int y)
{
    if (find(x)!=find(y))
	{
        f[find(y)] =find(x);
        return 1;
    }
    return 0;
}


int main(void)
{
	while(cin>>n>>v>>e)
    {
    	edge road[n+5];
    	for(int i=0; i<55; i++)
    		f[i]=i;
    	for(int i=0; i<e; i++)
			cin>>road[i].a>>road[i].z>>road[i].w;
		
		int cnt=0, k=0, sum=0;
		sort(road, road+e, cmp);
		for(int i=0; i<e; i++)
		{
			if((road[i].a==v||road[i].z==v)&&cnt<2)
			{	if(merge(road[i].a, road[i].z))
				{
					sum+=road[i].w;
					cnt++;
					k++;
			}	}
			else if(road[i].a!=v&&road[i].z!=v)
				if(merge(road[i].a, road[i].z))
					sum+=road[i].w, k++;
			if(k==n-1)
				break;
		}
		if(k==n-1&&cnt<=2)
			cout<<sum<<endl;
		else
			cout<<"-1"<<endl;
	}
	
    
    return 0;
}