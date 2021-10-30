#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n,r,d,s;
    cin>>r>>d>>n;
    if(fabs(r)<fabs(n))
    s=2*sqrt((fabs(n)-fabs(r))*(fabs(n)-fabs(r))+d*d)-abs(r);
    else
        s=2*fabs(d)-fabs(r);
    cout<<fixed<<setprecision(2)<<s;
}

