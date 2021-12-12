#include<bits/stdc++.h>
using namespace std;
int a[100000],dis[100000];
int n,m,i;
bool check(int t)
{
	int temp=t;
	int cnt=0;
	t-=n;
	for(int i=1;i<n;i++)
	{
		t-=dis[i];
		if(t<0)
		{
			break;
		}
		cnt++;
	}
	if(n-cnt<=m)
	{
		//cout<<temp<<" 1"<<endl;
		return true;
	}
	else
	{
		//cout<<temp<<" 0"<<endl;
		return false;
	}
}

int main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=1;i<n;i++)
		dis[i]=a[i]-a[i-1]-1;
	sort(dis+1,dis+n);
	//for(i=1;i<n;i++)
	//cout<<dis[i]<<' ';
	int l,r,ans;
	l=n;
	r=a[n-1]-a[0]+1;
	while(l<=r)
	{
		//cout<<"left"<<l<<' '<<"right"<<r<<endl;
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
