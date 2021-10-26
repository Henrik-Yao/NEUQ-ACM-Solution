#include<bits/stdc++.h>
using namespace std;
double r,d,n;
double ans;
int main()
{
	cin>>r>>d>>n;
	if(abs(n)-r<=0)
	{
		printf("%0.2lf",2*d-r);
		return 0;
	}
	if(n>0)
	{
		double ans1=sqrt(d*d+(n-r)*(n-r));
	    double ans2=sqrt(d*d+(n-r)*(n-r))-r;
	    ans=ans1+ans2;
	}
	else
	{
		double ans1=sqrt(d*d+(n+r)*(n+r));
	    double ans2=sqrt(d*d+(n+r)*(n+r))-r;
	    ans=ans1+ans2;
	}
	printf("%0.2lf",ans);
	return 0;
}
