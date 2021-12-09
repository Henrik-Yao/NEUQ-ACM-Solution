#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],step[1000001],ans=0x3f3f3f3f;
void search(int k,int s)
{
	if(k+a[k]>=n)
	{
		ans=s+1;
		return ;
	}
	int x=k+a[k],l=0;
	for(int i=k+1;i<=k+a[k];i++)
	{
		if(a[i]>=a[x]&&a[i]+i>a[k]+k)
		{
			x=i;
		}
	}
	l=a[x]+x;
	for(int i=x;i<=k+a[k];i++)
	{
		if(a[i]+i>l)
		{
			l=a[i]+i;
			x=i;
		}
	}
	search(x,s+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 	
	search(1,0);
	cout<<ans;
}