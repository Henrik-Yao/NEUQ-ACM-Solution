#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main() 
{
	int n,m,k,now=1;
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++)
	{
		a[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			int t=0;
			while(t<m-1)
			{
				now--;
				if(now==0) now=n;
				if(a[now]==0) t++;
			}
			a[now]=1;
			cout<<now<<" ";
		}
		else
		{
			int t=0;
			while(t<k-1)
			{
				now++;
				if(now>n) now=1;
				if(a[now]==0) t++;
			}
			a[now]=1;
			cout<<now<<" ";
		}
	}
}
