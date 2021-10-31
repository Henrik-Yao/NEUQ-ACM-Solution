#include<bits/stdc++.h> 
using namespace std;
int main()
{
	float r,d,n,ans;
	cin>>r>>d>>n;
	r=fabs(r);
	d=fabs(d);
	n=fabs(n);
	if(n-r<=0)//如果所画圆正好与直线相交 
	{
		ans=2*d-r;
	}
	else
	{
		ans=2*sqrt(d*d+(n-r)*(n-r))-r;//不相交情况 
	}
	printf("%.2f",ans);
	return 0;
}
