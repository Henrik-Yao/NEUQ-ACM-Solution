#include<bits/stdc++.h>
using namespace std;
int main(){
    float r,d,n;
    cin>>r>>d>>n;
    n=fabs(n),d=fabs(d);
    if(n<=r)
        printf("%.2f",2.0*d-r);
    else
        printf("%.2f",sqrt((n-r)*(n-r)+d*d)*2.0-r);
    return 0;
}
