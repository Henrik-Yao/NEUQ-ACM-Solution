#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
int a[1005];
int x;
int ans=-1,num;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>x;
	int l=0,r=n-1;
	while(l<=r)
	{
		num++;
		int mid=(l+r)>>1;
		if(x<a[mid])
		{
			r=mid-1;
		}
		else if(x>a[mid])
		{
			l=mid+1;
		}
		else if(x==a[mid])
		{
			ans=mid;
			break;
		}
	}
	cout<<ans<<endl<<num;
	return 0;
}
