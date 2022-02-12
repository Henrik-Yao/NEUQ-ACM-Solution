#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n,m;
int a[105];
int b[105];
int search(int x)
{
	int ans=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(x==a[mid])
		{
			ans=mid;
			break;
		}
		else if(x>a[mid])
		{
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++)cout<<a[i]<<" ";cout<<a[n]<<endl;
		cin>>m;
		for(int i=1;i<m;i++)
		{
			cin>>b[i];
			cout<<search(b[i])<<" ";
		}
		cin>>b[m];
		cout<<search(b[m]);
		cout<<endl;
	}
	return 0;
}
