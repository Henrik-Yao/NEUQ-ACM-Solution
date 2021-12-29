#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,i,j,k,t,id;
	int dis[202][202]={0};
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				dis[i][j]=dis[j][i]=1e9;
		for(i=0;i<n;i++)
		{
			cin>>id>>k;
			for(j=0;j<k;j++)
			{
				cin>>t;
				dis[id][t]=1;
			}
		}
		for(k=0;k<n;k++)
			for(j=0;j<n;j++)
				for(i=0;i<n;i++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		while(m--)
		{
			cin>>k>>t;
			if(dis[k][t]<1e9) cout<<dis[k][t];
			else cout<<"connection impossible";
			cout<<endl;
		}	
	}
    return 0;
}
