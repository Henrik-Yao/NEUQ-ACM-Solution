#include<bits/stdc++.h>
using namespace std;
const int k=10000+5;
int f[k],a[k];
int max_=INT_MIN;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        f[i]=a[i];
        f[i]=max(f[i-1]+f[i],f[i]);
        if(max_<f[i])
            max_=f[i];
    }
    if(max_<0)
        cout<<"0";
    else
        cout<<max_;
    return 0;
}
