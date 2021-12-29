#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,e;
	while(cin>>n>>e)
	{
		int a,b,c,w[100][100],t[100]={0},x;
		memset(w,10000,sizeof(w));
		for(int i=0;i<e;i++)
		{
			cin>>a>>b>>c;
			w[a][b]=c;
			w[b][a]=c;
		}
		for(int i=0;i<n;i++)
		{
			w[i][i]=0;
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(w[i][j]>w[i][k]+w[k][j])
					{
						w[i][j]=w[i][k]+w[k][j];
					}                 
				}                   
			}            
		}
		int min=1000000;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				t[i]+=w[i][j];
			}
			if(t[i]<min)
			{
				min=t[i];
				x=i;
			}
		}
		cout<<x<<endl;      
	}
	return 0;
}
