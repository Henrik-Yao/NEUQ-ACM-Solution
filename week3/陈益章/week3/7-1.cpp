#include <iostream>
using namespace std;
 struct amg
{
	int aaa[100][100];
	int vn,an; 
};
int safe[100],now,b,flag=0;
int main()
{
	int n;
	amg G;
	cin>>G.vn>>n>>G.an;
	for(int i=0;i<n;i++)
	cin>>safe[i];
	for(int i=0;i<G.vn;i++)
	{
		for(int j=0;j<G.vn;j++)
		{
			G.aaa[i][j]=0;
		}
	}
	for(int i=0;i<G.an;i++)
	{
		int x,y;
		cin>>x>>y;
		G.aaa[x][y]=1;
		G.aaa[y][x]=1;
	}
	cin>>now>>b;
	for(int i=0;i<n;i++)
	{
		if(b==safe[i])
		{
			flag=1;
			break;
		}
	}
	if(G.aaa[now][b]==1)
	{
		if(flag)
		printf("The city %d can arrive safely!\n",b);
		else 
			printf("The city %d is not safe!\n",b);
	}
	else
	{
		if(flag)
		printf("The city %d can not arrive safely!\n",b);
		else printf("The city %d is not safe!\n",b);
	}
}

