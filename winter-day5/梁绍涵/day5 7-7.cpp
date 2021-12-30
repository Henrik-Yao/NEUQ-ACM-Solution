#include<bits/stdc++.h>
using namespace std;
int n,m,best=-0x3f3f3f;
int a[200010];
int match(int x)
{
//	cout<<x<<endl;
	int s=1,k=2;
	int now=1;
	while(s!=m)
	{
		if(s!=m&&k==n+1)
		{
			return 0;
		}
		if(a[k]-a[now]>=x)
		{
			now=k;
			k++;
			s++;
		}
		else
		{
			k++;
		}
	}
	return 1;
}
void binary()
{
	int left=1,right=n;
	while(left<right)
	{
		if(left>right) return;
		int mid=(left+right)/2;
		if(match(mid))
		{
			if(best<mid)
			{
				best=mid;
				cout<<mid<<endl;
			}
			
			left=mid+1;
		}
		else if(!match(mid)) right=mid;
	}
	return ;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	binary();
	cout<<best;
}
