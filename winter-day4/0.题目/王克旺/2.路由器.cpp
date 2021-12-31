#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int n,m;
	int w[200][200];
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
	    {
		    for(int j=0;j<n;j++)
		    {
		    	w[i][j]=10;
		    }
	    }
		for(int j=0;j<n;j++)
	    {
		    int i,k,v;
		    cin>>i>>k;
		    for(int t=0;t<k;t++)
		    {
			    cin>>v;
			    w[i][v]=1;
		    }
	    }
	    for(int i=0;i<m;i++)
	    {
	    	int a,b,count=1;
	    	cin>>a>>b;
	    	for(int j=0;j<n;j++)
		    {
				if(w[a][b]>w[a][j]+w[j][b])
				{
					w[a][b]=w[a][j]+w[j][b];
					count++;
				}                                   
		    }
		    if(count==1&&w[a][b]!=1)
		    {
		    	cout<<"connection impossible"<<endl;
			}
			else
			{
				cout<<count<<endl;
			}
		}
	}
	return 0;
}
