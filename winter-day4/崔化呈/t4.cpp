#include<bits/stdc++.h>
using namespace std;

int show[105][105];
int pass[105][105];
const int maxx=999999;

void FLO(int vn)
{
	for(int k=0;k<vn;k++)
	{
		for(int i=0;i<vn;i++)
		{
			for(int j=0;j<vn;j++)
			{
				if(show[i][j]>show[i][k]+show[k][j])
				{
					show[i][j]=show[i][k]+show[k][j];
					pass[i][j]=k;
				}
			}
		}
	}
}
void print(int x,int y)
{
	if(pass[x][y]==-1){return;}
	print(x,pass[x][y]);
	printf("%d->",pass[x][y]);
	print(pass[x][y],y);
}
int main()
{
	int vn,en;
	fill(show[0],show[0]+105*105,maxx);
	fill(pass[0],pass[0]+105*105,-1);
	scanf("%d%d",&vn,&en); 
	while(en--)
	{
		int fr,to,w;
		scanf("%d%d%d",&fr,&to,&w);
		show[fr][to]=w;
	}
	//cout<<en<<endl;
	for(int i=0;i<vn;i++){show[i][i]=0;}
	FLO(vn);
	for(int i=1;i<=2;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d->",x);
		if(show[x][y]>=maxx)
		{
			printf("%d:-1\n",y);
			continue;
		}
		print(x,y);
		printf("%d:%d\n",y,show[x][y]);
	}
	int mx,my,mmax=0;
	for(int i=0;i<vn;i++)
	{
		for(int j=0;j<vn;j++)
		{
			if(show[i][j]>mmax&&show[i][j]<maxx)
			{
				mmax=show[i][j];
				mx=i;
				my=j;
			}
		}
	}
	printf("%d->",mx);
	print(mx,my);
	printf("%d:%d",my,mmax);
	return 0;
}
