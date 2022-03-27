#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
	int v,e,a,b,c,start,end;
	int w[100][100],pre[100],cost[100],visit[100];
	cin>>v>>e;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			w[i][j]=10000;
		}
	}
	for(int i=0;i<e/2;i++)
	{
		cin>>a>>b>>c;
		w[a][b]=w[b][a]=c;
	}
	cin>>start>>end;
	if(start==end)
    {
         cout<<start<<"-->"<<end<<":"<<0;
    }
    else
    {
    	memset(visit,0,sizeof(visit));
	    memset(pre,-1,sizeof(pre));
	    for(int i=0;i<v;i++)
	    {
		    cost[i]=w[start][i];
		    pre[i]=start;
	    }
	    pre[start]=-1;
	    visit[start]=1;
	    cost[start]=0;
	    for(int i=0;i<v-1;i++)
	    {
	    	int min=10000,k;
		    for(int j=0;j<v;j++)
		    {
			    if(visit[j]==0&&cost[j]<min)
			    {
			    	min=cost[j];
			    	k=j;
			    }
		    }
		    visit[k]=1;
		    for(int j=0;j<v;j++)
			{
		    	if(visit[j]==0&&cost[j]>min+w[k][j])
		    	{
		    		cost[j]=min+w[k][j];
		    		pre[j]=k;
		    	}
		    }
	    }
	    vector<int>ve;
	    int i=end;
	    while(i!=-1)
	    {
	      	ve.push_back(i);
	    	i=pre[i];		
	    }
	    for(int i=ve.size()-1;i>0;i--)
	    {
	    	cout<<ve[i]<<"-->";
	    }
	    cout<<end<<":"<<cost[end];
	}		
	return 0;
}
