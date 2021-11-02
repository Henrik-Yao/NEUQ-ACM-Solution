#include <bits/stdc++.h>
using namespace std;
struct amph
{
	int rs[110][110];
	int v, a;
}g;
int main(void)
{
	int n, csafe[110], x, y, in, dt, f=0;
	cin>>g.v>>n>>g.a;
	
	for(int i=0; i<n; i++)
		cin>>csafe[i];
	
	for(int i=0; i<g.v; i++)
		for(int j=0; j<g.v; j++)
			g.rs[i][j]=0;
	
	for(int i=0; i<g.a; i++)
	{
		cin>>x>>y;
		g.rs[x][y]=g.rs[y][x]=1;
	}
	cin>>in>>dt;
	for(int i=0; i<n; i++)
		if(dt==csafe[i])
		{
			f=1;
			break;
		}
	
	cout<<"The city "<<dt;
	if(g.rs[in][dt]==1)
	{
		if(f)
			cout<<" can arrive safely!";
		else
			cout<<" is not safe!";
	}
	else
	{
		if(f)
			cout<<" can not arrive safely!";
		else
			cout<<" is not safe!";
	}
	
	return 0;
}