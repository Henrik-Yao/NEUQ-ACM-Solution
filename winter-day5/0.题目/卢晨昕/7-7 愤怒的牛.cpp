#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n,m;
int ans;
int x[100005];
bool check(int a)
{
	int num=0;
	int pre;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			num++;
			pre=i;
		}
		else
		{
			if(x[i]-x[pre]>=a)
			{
				pre=i;
				num++;
			}
		}
	}
	if(num>=m)return true;
	else return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>x[i];
	sort(x+1,x+1+n);
	int l=0,r=x[n]-x[1];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

