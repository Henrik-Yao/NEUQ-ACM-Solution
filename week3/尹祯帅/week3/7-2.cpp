#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
bool ju[502],jud[502];
int temp[502][502],q[502],w[502];
int tuili(int a)
{
	ju[a]=1;
	if(q[a]) return q[a];
	for(int i=1;i<=n;i++)
	{
		if(temp[a][i]) 
		q[a]+=tuili(i);
		
	}return q[a];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		temp[a][b]=1;
	}
	cin>>a>>b;
	q[b]=1;
	cout<<tuili(a);
	int i;
	for(i=1;i<=n;i++)
	{
		if(ju[i]&&!q[i]) 
		{
			cout<<' '<<"No"<<'\n';
			break;
		}
	}
	if(i==n+1)  cout<<' '<<"Yes"<<'\n';
	return 0;
}
