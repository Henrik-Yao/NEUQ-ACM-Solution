#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
     int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
       cin>>a[i];
    int pos=lower_bound(a+1,a+1+n,k)-a;
    if (pos==-1) cout<<n+1;
    else cout<<pos;
    return 0;
}
