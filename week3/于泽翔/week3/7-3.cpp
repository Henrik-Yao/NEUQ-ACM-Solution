#include <bits/stdc++.h>
using namespace std;

int n, m, k, l, s[33][33], v[33][33], a, b, f=1;
const int dx[8]={-1, -1, -1, 0, 1, 1, 1, 0}, dy[8]={1, 0, -1, -1, -1, 0, 1, 1};

void test(int x, int y)
{
	int res=0, nx, ny;
	for(int i=0; i<8; i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		
		if(nx<1||nx>n||ny<1||ny>m)
			continue;
		if(s[nx][ny])
			res++;
	}
	v[x][y]=res;
	if(res)
		return;
	for(int i=0; i<8; i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		
		if(nx<1||nx>n||ny<1||ny>m)
			continue;
		else if(s[nx][ny]||v[nx][ny]!=-1)
			continue;
		test(nx, ny);
	}
}
int main(void)
{
	cin>>n>>m>>k>>l;
	while(k--)
	{
		cin>>a>>b;
		a++;
		b++;
		s[a][b]=1;
	}
	memset(v, -1, sizeof(v));
	while(l--)
	{
		cin>>a>>b;
		a++;
		b++;
		
		if(v[a][b]!=-1)
			continue;
		
		if(s[a][b])
		{
			cout<<"You lose"<<endl;
			return 0;
		}
		test(a, b);
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
				cout<<v[i][j]<<" ";
			cout<<endl;
		}
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				if(v[i][j]==-1&&!s[i][j])
					f=0;
		if(f)
		{
			cout<<"You win"<<endl;
			return 0;
		}
		cout<<" ";
	}
	//cout<<endl;
	return 0;
}