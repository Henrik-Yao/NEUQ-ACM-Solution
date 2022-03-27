#include <bits/stdc++.h>
using namespace std;
int main()
{
    //3情况，绝对值--两种，最下面
    float r,d,n;
    cin>>r>>d>>n;
    d=fabs(d);
    n=fabs(n);
    float s;
    if(n<=r)s=float(2)*d-r;
    else s=float(2)*sqrt(d*d+(n-r)*(n-r))-r;
    printf("%.2f",s);
    return 0;


}