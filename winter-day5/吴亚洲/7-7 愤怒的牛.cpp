#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
bool judge(int d)
{
	int cnt=0;
	for(int i=1;i<=n;)
	{
		int j;
		for(j=i+1;a[j]-a[i]<d&&j<=n;j++);
		if(j<=n&&a[j]-a[i]>=d)
		cnt++;
        i=j;
	}
	return cnt+1>=m;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=a[n]-a[1];
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
		l=mid+1;
		else
		r=mid-1;
	}
	cout<<r;
}
