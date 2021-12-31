#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[100005];
bool check(int dis)
{
	int tot=1,num=1;
	for(int i=num+1;i<=n;i++)
	{
		if(a[i]-a[num]>=dis)
		{
			num=i;
			tot++;
		}
		if(tot==m)break;
	}
	if(tot==m)return 1;
	else return 0;
}
int main()
{
	cin>>n>>m;	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=a[1],r=a[n]-a[1];
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
} 
