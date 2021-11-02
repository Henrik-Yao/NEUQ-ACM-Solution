#include<iostream>
using namespace std;
int f[1000005],t[1000005];
int a[1005][1005];
char s[1005][1005];
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int main()
{
	int n,m,cnt=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]+1;
		for(int j=1;j<=n;j++)
		{
			f[cnt]=cnt;
			a[i][j]=cnt++;
			if(i>1&&s[i-1][j]!=s[i][j])
			{
				f[find(a[i-1][j])]=find(a[i][j]);
			}
			if(j>1&&s[i][j-1]!=s[i][j])
			{
				f[find(a[i][j-1])]=find(a[i][j]);
			}
		}
	}	
	for(int i=1;i<cnt;i++)
	{
		t[find(i)]+=1;
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<t[find(a[u][v])]<<endl;
	}
}



