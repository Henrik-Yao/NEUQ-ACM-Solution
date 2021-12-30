#include <bits/stdc++.h>
using namespace std;
long long n,e,u,v,w,a[200][200],sum[200],pass[200][200];
void print(int x,int y)
{
	if(x==y)
	{
		return;
	}
	if(pass[x][y]==0)
	{
		cout<<x<<"->";
	}
	else
	{
		print(x,pass[x][y]);
		print(pass[x][y],y);
	}
}
int main()
{
	    cin>>n>>e;
		memset(sum,0,sizeof(sum));
		memset(pass,0,sizeof(pass));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
				{
					a[i][j]=0;
					a[j][i]=0;
				}
				else
				{
					a[i][j]=1e9;
					a[i][j]=1e9;
				}
			}
		}
		for(int i=0;i<e;i++)
		{
			cin>>u>>v>>w;
			a[u][v]=w;
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(a[i][j]>a[i][k]+a[k][j])
					{
						a[i][j]=a[i][k]+a[k][j];
						pass[i][j]=k;
					}
				}
			}
		}
		for(int i=1;i<=2;i++)
		{
			int st,en;
			cin>>st>>en;
			if(st==en)
			{
				cout<<st<<"->"<<en<<":"<<"0"<<endl;
				continue;
			}
			if(a[st][en]<1e9)
			{
			 print(st,en);
			 cout<<en<<":"<<a[st][en]<<endl;
		    }
		    else 
		    {
		    	cout<<st<<"->"<<en<<":"<<"-1"<<endl;
			}
		}
		int maxx=-1,ss,ee;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>=1e9)
				continue;
				else 
				{
					if(a[i][j]>maxx)
					{
						maxx=a[i][j];
						ss=i;
						ee=j;
					}
				}
			}
		}
		print(ss,ee);
		cout<<ee<<":"<<maxx;
	return 0;
}
