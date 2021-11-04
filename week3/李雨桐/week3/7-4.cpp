#include<bits/stdc++.h>

using namespace std;
int n,m,x,y,b[1005][1005],g,s[100005];
char a1[1005][1005];

void migong(int xi,int yi,int z,int x);

int main()
{

	memset(b,-1,sizeof(b));
	cin>>n>>m;
	for(int i=0;i<=n-1;i++)
	for(int j=0;j<=n-1;j++)
	cin>>a1[i][j];
	for(int i=0;i<=m-1;i++)
	{
		cin>>x>>y;
		x--;
		y--;

		if(b[x][y]==-1)
            migong(x,y,a1[x][y]-'0',i);
		else
		s[i]=s[b[x][y]];
	}
	for(int i=0;i<m;i++)
        cout<<s[i]<<endl;


	return 0;
}

void migong(int xi,int yi,int z,int x)
{
	if(xi<0||xi>=n||yi<0||yi>=n||b[xi][yi]!=(-1)||a1[xi][yi]-'0'!=z)
        return;

    b[xi][yi]=x;
	s[x]++;

	migong(xi-1,yi,!z,x);
	migong(xi+1,yi,!z,x);
	migong(xi,yi-1,!z,x);
	migong(xi,yi+1,!z,x);
}
