#include<bits/stdc++.h>
using namespace std;
int main()
{
	double r,d,n,sum;
	cin>>r>>d>>n;
	r=abs(r);
	n=abs(n);
	d=abs(d);
	if(r>=n) 
	{
		if(r>=(d+d))
		{
			sum=0;
		}
		else
		sum=d+d-r;
	}
	else
	{
		sum=0;
		sum+=sqrt((n-r)*(n-r)+d*d)*2-r;
	}
	printf("%.2f",sum);
	return 0;
}