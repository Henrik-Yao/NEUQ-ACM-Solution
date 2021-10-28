#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double s,d,n,r,l;
    cin>>r>>d>>n;
    d=fabs(d);
    n=fabs(n);
    if(r<n)
    {
        l=n-r;
    	s=2.0*sqrt(d*d+l*l)-r;
    }
    else  s=2*d-r;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<s;
    return 0;
}
