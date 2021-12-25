#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(n<=m){
        cout<<n;
        return 0;
    }
    int a[n*2];
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    sort(a+1,a+n+1);
    int b[n*2];
    for(int i=1;i<=n-1;i++){
        b[i]=a[i+1]-a[i];
    }
    sort(b+1,b+n);
    int ans;
    int count=n-m;
    ans=n;
    for(int i=1;i<=count;i++){
        ans=ans+b[i]-1;
    }
    cout<<ans;
    return 0;
 
}
