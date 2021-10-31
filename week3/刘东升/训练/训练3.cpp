#include<iostream>
using namespace std;
const int M=50; 
int map[M][M],bo[M][M],vis[M][M],map1[M][M];
int n,m,k,l,num;
int xv[8]={0,0,1,1,1,-1,-1,-1};
int yv[8]={-1,1,-1,0,1,-1,0,1};
bool pd(int x,int y);
int get(int x,int y);	
void fuc(int x,int y);
int main()
{
	cin>>n>>m>>k>>l;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			map[i][j]=-1;//标记  
		}
	}
	for(int i=1;i<=k;i++)
	{
		int xi,yi;
		cin>>xi>>yi;//标记 雷 
		bo[xi][yi]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			map1[i][j]=get(i,j);//给map赋值 
		}
	}
	while(l--)//l次操作 
	{
		int xi,yi;
		cin>>xi>>yi;
		if(bo[xi][yi]==1)//如果点到雷 
		{
			cout<<"You lose";
			break;
		}
		if(map[xi][yi]!=-1) continue;//点到空 
		if(map[xi][yi]==-1)
		{ 
			fuc(xi,yi);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					cout<<map[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		if(n*m-k==num)//全部点开了 
		{
			puts("You win");
			return 0;
		}
		cout<<endl;
	}
	return 0;
}
bool pd(int x,int y)
{
	int t=0;
	for(int i=0;i<8;i++)
	{
		int xi,yi;
		xi=x+xv[i];
		yi=y+yv[i];
		if(xi<0||xi>=n||yi<0||yi>=m) continue;
		if(bo[xi][yi]==1) t=1;
	}
	if(t==1)
	{
		return 0;
	}
	else return 1;
}
int get(int x,int y)
{
	int res=0;
	for(int i=0;i<8;i++)
	{
		int xi,yi;
		xi=x+xv[i];
		yi=y+yv[i];
		if(xi<0||xi>=n||yi<0||yi>=m) continue;
		if(bo[xi][yi]==1) res++;
	}
	return res;
}
void fuc(int x,int y)//拓展 
{
	vis[x][y]=1;
	num++;
	if(pd(x,y)==1)
	{
		map[x][y]=map1[x][y];
		for(int i=0;i<8;i++)
		{
			int xi,yi;
			xi=x+xv[i];
			yi=y+yv[i];
			if(xi<0||xi>=n||yi<0||yi>=m||vis[xi][yi]) continue; 
			fuc(xi,yi);
		}
		return; 
	}
	else
	{
		map[x][y]=map1[x][y];
		return;
	}
}	
