#include<bits/stdc++.h>
using namespace std;
int w[2000],v[2000];
int dp1[2000][2000],dp2[2000];
int x,y ;
int p( int a, int b )
{
	if(a>b)
	return a;
	else
	return b;
} 
int main()
{
    while(scanf("%d %d",&x,&y )!=EOF)
    {
       	for( int i=1;i<=x;i++ )
		   cin>>w[i];
        for( int i=1;i<=x;i++ )
			cin>>v[i];
        memset(dp1,0,sizeof(dp1)) ;
		for(int j=0;j<=y;j++ )
        {
            if(j>=w[1]) 
			dp1[1][j]=v[1] ;
        }
        for(int i=2;i<=x;i++)
        {
            for(int j=0;j<=y;j++ )
        	{
                if(j-w[i]>=0)
                {
                    dp1[i][j]=p(dp1[i-1][j],dp1[i-1][j-w[i]]+v[i] ) ;
                }
                else
                {
                    dp1[i][j]=dp1[i-1][j] ;
                }
            }
        }
 		cout<<dp1[x][y]<<endl;
     }
     return 0 ;
 }
