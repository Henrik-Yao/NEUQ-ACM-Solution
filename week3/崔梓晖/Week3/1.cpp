#include <bits/stdc++.h>
using namespace std;
int m,n,k,aq,pd[501],a[501][501],s,d,x,y,flag=0;
void dfs(int s)
{
	if(s==d)
	{
		flag=1;
		cout<<"The city "<<d<<" can arrive safely!";
		return;
	}
	else{
	for(int i=0;i<m;i++)
	{
		if(a[s][i]==1&&pd[i]==1)
		{
			pd[i]=2;
			dfs(i);
		}
	}
	return;
}
}
int main()
{
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>aq;
		pd[aq]=1;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	cin>>s>>d;
	if(pd[d]!=1)
	{
	cout<<"The city "<<d<<" is not safe!";
	return 0;
    }
	pd[s]=2;
	dfs(s);
	if (flag==0) 
	cout<<"The city "<<d<<" can not arrive safely!";
	return 0;
}
