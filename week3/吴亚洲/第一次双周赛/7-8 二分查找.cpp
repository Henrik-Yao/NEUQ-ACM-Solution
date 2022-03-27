#include<bits/stdc++.h>
using namespace std;
long long n,num,m;
int a[1000001];
int main()
{
	cin>>n>>m;
	for(int long long i=1;i<=n;i++)
	cin>>a[i];
	long long l=1,r=n;
	if(m>a[n])
	cout<<n+1;
	else
	{
		while(l!=r)
		{
			long long mid=(l+r)/2;
			if(a[mid]>=m)
			r=mid;
			else
			l=mid;
			if(a[mid]>=m&&a[mid-1]<m)
			{
				cout<<mid;
				break;
			}
		}
	}
}
