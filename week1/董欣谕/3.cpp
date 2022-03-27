#include <bits/stdc++.h>
using namespace std;
int main(){
	long long r,d,n;
	double ans;
	cin>>r>>d>>n;
    d=abs(d);
    n=abs(n);
    if (d*2<=r) ans=0;
    else
	if (n<=r) ans=2*d-r;
	else {
		ans=2*sqrt(d*d+(n-r)*(n-r))-r;
	}
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}
