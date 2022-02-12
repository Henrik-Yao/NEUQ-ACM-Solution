#include<bits/stdc++.h>
using namespace std;
const int M=1e4+5;
struct N
{
	string name;
	int tarrive;
	int twait;
}a[M];
map<string,int> link;
int ptime,num,nans=1;
double wtime;
int ans[M],f[M];
bool finished[M];
int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int k;
		string s;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>s;
			f[link[s]=++num]=m+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].name>>a[i].tarrive>>a[i].twait;
		if(a[i].twait>60)
		a[i].twait=60;
	}
	for(int i=1;i<=n;i++)
	{
		if(finished[i]) continue;
		int d=f[link[a[i].name]],j=i;
		do{
			if(finished[j] || f[link[a[j].name]]!=d)
			{
				j++;
				continue;
			}
			wtime+=max(0,ptime-a[j].tarrive);
			ans[nans++]=j; 
			ptime=max(ptime,a[j].tarrive)+a[j].twait;
			finished[j++]=1;
		}
		while(d && j<=n && a[j].tarrive<=ptime);
	}
	for(int i=1;i<=n;i++)
	cout<<a[ans[i]].name<<endl;
	printf("%.1f\n",wtime/n);
}
