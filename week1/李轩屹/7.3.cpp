#include<bits/stdc++.h>
using namespace std;
int main()
{
	double r,d,n;
	cin>>r>>d>>n;
	r=fabs(r),d=fabs(d),n=fabs(n);
	double x;
	if(n>r) x=2*sqrt((n-r)*(n-r)+d*d)-r;
	else x=2*d-r;
	cout<<fixed<<setprecision(2)<<x;
	return 0;
}
