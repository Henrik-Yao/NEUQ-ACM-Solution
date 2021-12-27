#include<bits/stdc++.h>
using namespace std;
typedef long long ull;//不可使用unsigned；
const long long mmax=1e6+1;
ull a[mmax];
ull n,q;
ull ope,i,x,ll,rr;
ull tree[mmax];
void build(ull p,ull l,ull r){
    if(l==r){
    tree[p]=a[l];return;
    }
        ull mid=(l+r)>>1;
        build(p*2,l,mid);
        build(p*2+1,mid+1,r);
        tree[p]=tree[p*2]+tree[p*2+1];
}//建树的操作
void change(ull p,ull l,ull r,ull i,ull x){
    if(i<l||i>r) return;
    if(l==r){
        tree[p]+=x;return;
    }
    ull mid=(l+r)>>1;
    if(i<=mid) change(p*2,l,mid,i,x);
    else change(p*2+1,mid+1,r,i,x);
    tree[p]=tree[p*2]+tree[p*2+1];
}//修改的操作
ull ssum(ull p,ull l,ull r,ull ll,ull rr){
    if(ll<=l&&rr>=r){
        return tree[p];
    }
     ull mid=(l+r)>>1;
    if(rr<=mid){
        return ssum(p*2,l,mid,ll,rr); 
    }
    if(ll>mid){
        return ssum(p*2+1,mid+1,r,ll,rr);
    }
    return (ssum(p*2,l,mid,ll,mid)+ssum(p*2+1,mid+1,r,mid+1,rr));
}//求和操作
int main(){
    scanf("%lld%lld",&n,&q);
    for(int j=1;j<=n;j++){
        cin>>a[j];
    }
    build(1,1,n);
    while(q--){
        scanf("%lld",&ope);
        if(ope==1){
            scanf("%lld%lld",&i,&x);
            change(1,1,n,i,x);
        }
        else if(ope==2){
        	scanf("%lld%lld",&ll,&rr);
			ull ans=ssum(1,1,n,ll,rr);
            printf("%lld\n",ans);
        }
        else;
    }
    return 0;
}