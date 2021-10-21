#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int>city[10001];
int n,m,flag[10001];
bool judge()
{
	int i,j,t; 
	for(i=1;i<=n;i++)
	{
		if(flag[i]!=1)
		{
			for(j=1;j<city[i].size();j++)
			{
				t=city[i][j];
				if(flag[t] == 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	int k;
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		city[x].push_back(y);
		city[y].push_back(x);
	}
	cin>>k;
	while(k--)
	{	    
		int np;
		cin>>np;		
		while(np--)
		{
			int x;
			cin>>x;
			flag[x]=1;				 
		}
		if(judge())
		{
		    cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		memset(flag,0,n+1);	
	}
	return 0;
}

