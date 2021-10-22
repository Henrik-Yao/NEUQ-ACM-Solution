#include <bits/stdc++.h>
using namespace std;
int main()
{
	double r,d,n;
	cin>>r>>d>>n;
	r=fabs(r);
	d=fabs(d);
	n=fabs(n);
	if(n<r)
	{
		cout<<fixed<<setprecision(2)<<(2*d-r);
	}
	else
	{
		cout<<fixed<<setprecision(2)<<2*sqrt(d*d+(n-r)*(n-r))-r;
	}
	return 0;
}
