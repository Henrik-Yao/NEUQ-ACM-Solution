#include<bits/stdc++.h>
using namespace std;
int arr[100000],dis[100000];
int n,m,i;
bool check(int t)
{
	int temp=t;
	int ans=0;
	t-=n;
	for(int i=1;i<n;i++)
	{
		t-=dis[i];
		if(t<0)
		{
			break;
		}
		ans++;
	}
	if(n-ans<=m)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
int main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	for(i=1;i<n;i++)
		dis[i]=arr[i]-arr[i-1]-1;
	sort(dis+1,dis+n);
	int l,r,ans;
	l=n;
	r=arr[n-1]-arr[0]+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	cout<<ans;
	return 0;
}
