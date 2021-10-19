#include<bits/stdc++.h>
using namespace std;
int main(){
    double ans;
    int r,d,n;
    cin>>r>>d>>n;
    r=fabs(r);
    d=fabs(d);
    n=fabs(n);
    if(n-r<=0)ans=2*d-r;
    else ans=2*sqrt(d*d+(n-r)*(n-r))-r;
    if(ans<0)ans=0;
    printf("%.2f",ans);
    return 0;
}
