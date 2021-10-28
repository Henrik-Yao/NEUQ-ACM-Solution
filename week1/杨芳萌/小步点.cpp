#include<bits/stdc++.h>
using namespace std;
double n,r,d,ans;
int main() { 
    scanf("%lf%lf%lf",&r,&d,&n);
    n=fabs(n);
    if(n>=r) ans = 2*sqrt(d*d+(n-r)*(n-r))-r;
    else ans = 2*d-r;
    printf("%.2lf\n",ans);
  return 0;  
}
