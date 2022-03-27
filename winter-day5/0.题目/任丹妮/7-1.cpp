#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    int a[10001];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        if(abs(a[i]-a[i+1])==1) ans++;
    }
    cout<<ans<<endl;
}
