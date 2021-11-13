#include <iostream>
using namespace std;

int n,s,f;
int m[50010],v[50010];

void dfs(int x)
{
	v[x]=1;
	if(!m[x]) {
	f=1;return;}
	if(x+m[x]<=n&&!v[x+m[x]]) dfs(x+m[x]);
	if(x-m[x]>=1&&!v[x-m[x]]) dfs (x-m[x]);
}

int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	cin>>s;
	dfs(s+1);
	if(f) cout<<"True";
	else cout<<"False";
	return 0;
}