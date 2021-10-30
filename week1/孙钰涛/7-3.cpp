#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double r,d,n;
    cin>>r>>d>>n;
    double result1=2*sqrt(d*d+(n-r)*(n-r))-r;
    double result2=2*sqrt(d*d+(n+r)*(n+r))-r;
    if((n+r)*n<=0 || (n-r)*n<=0) printf("%.2lf",2*d-r);
    else printf("%.2lf",min(result1,result2));
    return 0;
}