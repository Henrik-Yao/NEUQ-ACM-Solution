#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100005];
bool jud(int mid)
{
	int begin=0;
	int count = 1;
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[begin]>=mid) 
	{
		count++;
		begin=i;
	}
	}
	if(count>=m) return 1;
	else return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int left=0,right=n-1,ans=1e9;
	while(right>=left)
	{
		int mid=(right+left)/2;
		if(jud(mid))
		{
			ans=mid;
			left=mid+1;
		}
		else right = mid-1;
	}
	cout<<ans;
	return 0;
} 
