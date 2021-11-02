#include<bits/stdc++.h>
using namespace std;
int a[10001],ans=0;
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum<0) sum=0;
		ans=max(ans,sum);
	}
	cout<<ans;
}
