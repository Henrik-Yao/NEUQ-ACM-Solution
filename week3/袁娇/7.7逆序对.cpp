#include <iostream>
#include<cstdio> 
#include<cstring>
#define ll long long
using namespace std;
ll a[1000005],d[1000005];
ll sum=0;
void msort(int l,int r){
    if(l>=r) return;
    int mid=(l+r)>>1;
    msort(l,mid);msort(mid+1,r);
    int i=l,j=mid+1,t=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            d[t++]=a[i++];
        }else{
            d[t++]=a[j++];
            sum+=mid-i+1;
        }
    }
    while(i<=mid) d[t++]=a[i++];
    while(j<=r) d[t++]=a[j++];
    for(int k=l;k<=r;k++) a[k]=d[k];
}
int main(int argc, char** argv) {
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        memset(d,0,sizeof(d));
        sum=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
         
        msort(1,n);
        printf("%lld\n",sum);
    }
    return 0;
}
