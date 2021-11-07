#include<bits/stdc++.h>
#define M 100

typedef struct
{
	int arcs[M][M];
	int vexnum,arcnum;
}AMGraph;

int main()
{
	int n;
	AMGraph G;

	scanf("%d %d %d",&G.vexnum, &n, &G.arcnum );
	int safecity[M];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&safecity[i]);
	}
	for(int i=0;i<G.vexnum;i++)
	{
		for(int j=0;j<G.vexnum;j++)
		{
			G.arcs[i][j]=0;//赋初值
		}
	}
	for(int i=0;i<G.arcnum;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		G.arcs[x][y]=1;
		G.arcs[y][x]=1;
	}
	int now,de,flag=0;//当前，目的地城市
	scanf("%d %d",&now,&de);
	for(int i=0;i<n;i++)
	{
		if(de==safecity[i])
		{
			flag=1;
			break;
		}
	}
	if(G.arcs[now][de]==1)
	{
		if(flag)
        {
            printf("The city %d can arrive safely!\n",de);
        }
		else
		{
			printf("The city %d is not safe!\n",de);
		}
	}
	else
	{
		if(flag)
        {
            printf("The city %d can not arrive safely!\n",de);
        }

		else
        {
            printf("The city %d is not safe!\n",de);
        }
	}
	return 0;
}
