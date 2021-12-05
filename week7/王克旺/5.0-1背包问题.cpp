#include<bits/stdc++.h>
using namespace std;
int w[401],v[401],sum[401][1501];
int main()
{
    int n,c,i,j;
	while(cin>>n>>c)
	{	    
        memset(sum,0,sizeof(sum));
		for(i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		for(i=1;i<=n;i++)
		{
			cin>>v[i];
		}
    	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=c;j++)
    	    {
    	        if(j<w[i])
    	        {
    	        	sum[i][j]=sum[i-1][j];
				}              
    	        else
    	        {
     		       	sum[i][j]=max(sum[i-1][j],sum[i-1][j-w[i]]+v[i]);
				}      
    	    }
    	}
    	cout<<sum[n][c]<<endl;
	}
	return 0;
}
