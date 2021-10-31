#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[1005][1005];
int a[1005][1005];
int ss[100005];
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};

void dfs(int x1,int y1,int z)
{
    if(x1<1||x1>n||y1<1||y1>n)
    return;
    f[x1][y1]=z;
	ss[z]++;
	for(int j=0;j<4;j++)
	if(a[x1+x[j]][y1+y[j]]!=a[x1][y1]&&f[x1+x[j]][y1+y[j]]==-1)
	dfs(x1+x[j],y1+y[j],z);
}
int main()
{
    memset(f,-1,sizeof(f));
    memset(ss,0,sizeof(ss));
    cin>>n>>m;
    int i,j;
    int x,y;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            char ch;
	    	cin>>ch;
	    	if(ch=='1') a[i][j]=1;
	    	else a[i][j]=0;
        }
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
       if(f[x][y]==-1)
		{
			f[x][y]=i;
			dfs(x, y, i);
		}
		else
			ss[i]=ss[f[x][y]];
    }

    for(i=0;i<m;i++)
    cout<<ss[i]<<"\n";
    return 0;
}