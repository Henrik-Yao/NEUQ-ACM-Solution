#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[1001],x,pd=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>x;
	int l=0,r=n-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		ans++;
		if(x==a[mid])
		{
		 cout<<mid<<endl;
		 pd=1;
		 break;
	    }
		if(x>a[mid])
		{
			l=mid+1;
		}
		if(x<a[mid])
		{
			r=mid-1;
		}
	}
	if(pd==1)
	{
		cout<<ans;
	}
	if(pd==0)
	{
		cout<<"-1"<<endl;
		cout<<ans;
	}
	return 0;
}
