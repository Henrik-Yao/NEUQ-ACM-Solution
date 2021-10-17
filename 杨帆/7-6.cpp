#include<bits/stdc++.h>
using namespace std;
const int k=100000+5;
int v[k],t[k];
int main(){
    int n,time;
    int max_=INT_MIN;
    cin>>n>>time;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>t[i];
        if(time>t[i])
            max_=max(max_,v[i]);
        else
            max_=max(max_,v[i]-(t[i]-time));
    }
    cout<<max_;
}
