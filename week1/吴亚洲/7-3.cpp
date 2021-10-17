#include<bits/stdc++.h>
using namespace std;
int main()
{
	double r,d,n;
	cin>>r>>d>>n;
	cout<<fixed<<setprecision(2);
    n=abs(n);
    if(n-r>0)
	cout<<(2*sqrt(d*d+(n-r)*(n-r))-r);
	else
	cout<<(abs(2*d)-r);
	return 0;
}
