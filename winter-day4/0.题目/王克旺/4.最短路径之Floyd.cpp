#include<bits/stdc++.h>
#include<vector>
using namespace std;
int w[100][100],w1[100][100];
int pre[100],cost[100],visit[100];
void Dijkstra(int start,int end,int v)
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
	   	int min=1000000,k;
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
}  
int main()
{
	int v,e,a,b,c,start,end;	
	cin>>v>>e;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i==j)
			{
				w[i][j]=0;
				w1[i][j]=0;
			}
			else
			{
				w[i][j]=10000000;
				w1[i][j]=10000000;
			}
		}
	}
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>c;
		w[a][b]=c;
		w1[a][b]=c;
	}
	for(int t=1;t<=2;t++)
	{
	    cin>>start>>end;
	    if(start==end)
        {
            cout<<start<<"->"<<end<<":"<<0<<endl;
        }
        else
        {
        	Dijkstra(start,end,v);
		    vector<int>ve;
		    int i=end;
		    while(i!=-1)
		    {
		   	    ve.push_back(i);
		   	    i=pre[i];		
		    }
		    if(cost[end]!=10000000)
		    {
		        for(int i=ve.size()-1;i>0;i--)
		        {
	 	            cout<<ve[i]<<"->";
		        }
		        cout<<end<<":"<<cost[end]<<endl;
		    }
		    else
		    {
	 	  	    cout<<start<<"->"<<end<<":"<<-1<<endl;
		    }
		}    	
	}
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(w1[i][j]>w1[i][k]+w1[k][j])
				{
					w1[i][j]=w1[i][k]+w1[k][j];
				}                 
			}                   
		}            
	}
	int max=0,p,q;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(w1[i][j]<10000000&&w1[i][j]>max)
			{
				max=w1[i][j];
				p=i;
				q=j;
			}
		}
	}
	Dijkstra(p,q,v);
	vector<int>ve;
	int i=q;
	while(i!=-1)
	{
	   	ve.push_back(i);
	   	i=pre[i];		
	}
	for(int i=ve.size()-1;i>0;i--)
	{
	    cout<<ve[i]<<"->";
	}
	cout<<q<<":"<<cost[q];
	return 0;
}
