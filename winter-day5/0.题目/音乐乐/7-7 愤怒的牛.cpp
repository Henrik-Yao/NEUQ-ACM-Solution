#include<bits/stdc++.h>
using namespace std;
int a[100001];
int n,m,i;
bool check(int t)
{
	int cnt=m-1;
	int now=0;
	for(i=1;i<n;i++)
	{
		if(a[i]-a[now]>=t)
		{
			now=i;
			cnt--;
			if(cnt==0)
			break;
		}
	}
	//cout<<"t:"<<t<<" cnt:"<<cnt<<endl;
	if(cnt)
		return false;
	else
		return true;
}

int main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	/*for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;*/
	int l=1,r=a[n-1]-a[0];
	int ans;
	while(l<=r)
	{
		//cout<<"left"<<l<<' '<<"right"<<r<<endl;
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
