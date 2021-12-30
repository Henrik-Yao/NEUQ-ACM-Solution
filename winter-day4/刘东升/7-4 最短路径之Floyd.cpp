#include<bits/stdc++.h>
using namespace std;
int _map[105][105];
int pass[105][105];
int n,e,from,to;
void Floyd()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
	if(_map[i][j]>_map[i][k]+_map[k][j])
	{
		_map[i][j]=_map[i][k]+_map[k][j];
		pass[i][j]=k;
	}
}
void print(int from,int to)
{
	if(pass[from][to]==-1)
	return ;
	print(from,pass[from][to]);
	cout<<pass[from][to]<<"->";
	print(pass[from][to],to);
}
int main()
{
	memset(pass,-1,sizeof(pass));
	memset(_map,0x3f,sizeof(_map));
	cin>>n>>e;
	while(e--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		_map[x][y]=z;
	}
	for(int i=0;i<n;i++)
	_map[i][i]=0;
	Floyd();
	int x,y;
	for(int i=1;i<=2;i++)
	{
		cin>>x>>y;
		cout<<x<<"->";
		if(_map[x][y]>1000000)
		{
			cout<<y;
			cout<<":"<<-1<<endl;
			continue;
		}
		print(x,y);
		cout<<y;
		cout<<":"<<_map[x][y]<<endl;
	}
	int mx,my,max=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(_map[i][j]>max&&_map[i][j]<1000000)
	{
		max=_map[i][j];
		mx=i;
		my=j;
	}
	cout<<mx<<"->";
	print(mx,my);
	cout<<my<<":"<<max;
}
