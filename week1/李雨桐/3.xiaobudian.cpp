#include <bits/stdc++.h>
using namespace std;

int main()
{
    double r,d,n;

    cin>>r>>d>>n;


    if (fabs(n)>=r)
        printf("%.2lf",2.0*sqrt(fabs(d)*fabs(d)+(fabs(n)-r)*(fabs(n)-r))-r);
    else
        printf("%.2lf",2.0*fabs(d)-r);

    return 0;
}
