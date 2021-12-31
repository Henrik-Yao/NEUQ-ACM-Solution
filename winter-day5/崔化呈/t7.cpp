#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001000];
bool judge(int mid)
{
	int ans=1;
	int last=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[last]>=mid)
		{
			ans++;
			last=i;
		}
	}
	//cout<<ans<<endl;
	if(ans>=m){return 1;}
	else{return 0;}
}
int main()
{
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
	int l,r;
	l=1;r=a[n]-a[1];
	sort(a+1,a+1+n);
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(judge(mid)){l=mid+1;}
		else{r=mid-1;}
	}
	printf("%d",r);
	return 0;
}
