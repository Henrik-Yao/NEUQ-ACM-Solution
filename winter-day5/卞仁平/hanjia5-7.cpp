
#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100005];
bool is(int mid)
{
	int sitart=0;
	int cc = 1;
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[sitart]>=mid) 
	{
		cc++;
		sitart=i;
	}
	}
	if(cc>=m) return 1;
	else return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int l=0,r=n-1,ans=1e9;
	while(r>=l)
	{
		int mid=(r+l)/2;
		if(is(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r = mid-1;
	}
	cout<<ans;
	return 0;
} 
