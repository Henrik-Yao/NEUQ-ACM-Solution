#include<bits/stdc++.h>
using namespace std;
int main()
{
	double r,d,n;
	cin>>r>>d>>n;
	r=fabs(r);
	d=fabs(d);
	n=fabs(n);
	double l;
	if(n-r>0)
	{
		l=sqrt(d*d+(n-r)*(n-r))*2-r;
	}
	else
	{
		l=2d-r;
	}
	printf("%.2f",l);
    return 0;
}
//考虑原与坐标轴相交的情况