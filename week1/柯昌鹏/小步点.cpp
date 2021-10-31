#include <bits/stdc++.h>
using namespace std;
int main()
{
    double r,d,n;
    cin>>r>>d>>n;
    d=fabs(d);
    n=fabs(n);
    if(n>=r) printf("%.2lf",2.0*sqrt((n-r)*(n-r)+d*d)-r);
    else printf("%.2lf",2*d-r);
    return 0;
}
