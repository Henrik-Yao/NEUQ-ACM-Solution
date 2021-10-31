#include <iostream>
using namespace std;
#define MAXN 111

typedef struct 
{
	int arcs[MAXN][MAXN];
	int vex,arc;
}Graph;

int main()
{
	int n;//n个安全城市
	Graph G;
	cin>>G.vex>>n>>G.arc;
	int safecity[MAXN];
	for(int i=0;i<n;i++)
	{
		cin>>safecity[i];
	}
	G.arcs[MAXN][MAXN] =0;
	while(G.arc--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		G.arcs[x][y]=1;
		G.arcs[y][x]=1;
	}
	int now,destination,flag=0;
	scanf("%d %d",&now,&destination);
	for(int i=0;i<n;i++)
	{
		if(destination==safecity[i])
		{
			flag=1;
			break;
		}
	}
	if(G.arcs[now][destination]==1)
	{
		if(flag)
		printf("The city %d can arrive safely!\n",destination);
		else 
		{
			printf("The city %d is not safe!\n",destination);
			
		}
	}
	else
	{
		if(flag)
		printf("The city %d can not arrive safely!\n",destination);
		else printf("The city %d is not safe!\n",destination);
	}
	return 0;
}

