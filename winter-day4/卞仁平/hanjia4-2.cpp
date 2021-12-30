#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int n,m,i,k,j,a,b,c;
	while(cin>>n>>m)
	{
		ll tu[205][205];
		for(i=0;i<=n;i++)
		    for(j=0;j<=n;j++) 
                tu[i][j]=999;
		for(i=0;i<n;i++)
		{
			tu[i][i]=0;
			cin>>a>>c;
			while(c--)	
			{
				cin>>b;
				tu[a][b]=1;
			}
		}
		for(k=0;k<n;k++)
		    for(i=0;i<n;i++)
		        for(j=0;j<n;j++)
		            if(tu[i][j]>tu[i][k]+tu[k][j])                  
                        tu[i][j]=tu[i][k]+tu[k][j];
		while(m--)
		{
			cin>>a>>b;
			if(tu[a][b]>=999)
            cout<<"connection impossible\n";
			else 
            cout<<tu[a][b]<<'\n';
		}
	}
	return 0;
} 
