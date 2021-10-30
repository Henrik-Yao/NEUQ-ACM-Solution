#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int r,d,n;
	double s; 
	cin>>r>>d>>n;
    n=abs(n);
	if(r>n) s=2*d-r;
	else s=2*sqrt(d*d+(n-r)*(n-r))-r;
	cout<<fixed<<setprecision(2)<<s;
}
