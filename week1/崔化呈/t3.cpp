#include<bits/stdc++.h>
using namespace std;
int main()
{
	double dis,r,d,n;
	cin>>r>>d>>n;
    d=abs(d);
    n=abs(n);
	if(n>r){dis=2.0000*sqrt(d*d+(n-r)*(n-r))-r;}
	else{dis=2.0000*d-r;}
	cout<<fixed<<setprecision(2)<<dis;
	return 0;
}
