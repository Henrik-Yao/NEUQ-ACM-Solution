#include <bits/stdc++.h>
using namespace std;
int n,m,x[100101];
bool check(int d){
    int cow=1;
    int mind=d+x[0];
    for(int i=1;i<n;i++){
        if(x[i]<mind) continue;
        cow++;
        mind=x[i]+d;
    }
    return cow>=m;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>x[i];
    sort(x,x+n);
    int l=0,mid;
    int r=x[n-1]-x[0];
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r<<endl;
}
