#include <bits/stdc++.h>
using namespace std;
int main() {
    double n,r,d;
    cin>>r>>d>>n;
    d=abs(d);n=abs(n);
    if(r>=n) printf("%.2f\n",2*d-r);
    else printf("%.2f",sqrt((n-r)*(n-r)+d*d)*2-r);
    return 0;
}