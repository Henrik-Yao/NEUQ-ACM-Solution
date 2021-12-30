#include<bits/stdc++.h>
using namespace std;
const int M=999999;
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int dis[210][210];
		fill(dis[0],dis[0]+210*210,M);
		for(int i=0;i<n;i++){dis[i][i]=0;}
		int x,y,num;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&num);
			while(num--)
			{
				scanf("%d",&y);
				dis[x][y]=1;
			}
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(dis[a][b]>=n){printf("connection impossible\n");}
			else{printf("%d\n",dis[a][b]);}
		}
	}
	return 0;
}
