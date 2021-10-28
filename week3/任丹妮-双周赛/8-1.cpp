#include <bits/stdc++.h>
using namespace std;
int a[10001];
int find(int l,int r){
    if(l==r) return a[l];
    int mid=(l+r)/2;
    int L=find(l,mid),R=find(mid+1,r),sum1=0,sum2=0,ll=-1e9,lr=-1e9;
    for(int i=mid;i>=l;i--){
        sum1+=a[i];
        ll=max(ll,sum1);
    }
    for(int i=mid+1;i<=r;i++){
        sum2+=a[i];
        lr=max(lr,sum2);
    }
    return max(max(L,R),max(lr+max(ll,0),ll+max(lr,0)));
}
int main(){
    int n,flag=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<0) flag++;
    }
    if(flag==n) cout<<"0"<<endl;
    else cout<<find(1,n)<<endl;
}
