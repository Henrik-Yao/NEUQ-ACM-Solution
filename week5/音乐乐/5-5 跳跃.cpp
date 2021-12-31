#include<bits/stdc++.h>
using namespace std;
int a[50005];
int v[50005];
int n;
int flag=0;
void dfs(int p)
{
	v[p]=1;
	if(!a[p])
	{
		flag=1;
		return;
	}
	int x=p+a[p];
	if(x<=n&&!v[x]) 
	dfs(x);
	int y=p-a[p];
	if(y>=1&&!v[y])
	dfs(y);
}
int main()
{
	int start,i;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cin>>start;
	++start;
	dfs(start);
	if(flag)
	cout<<"True";
	else
	cout<<"False";
	return 0;
}
