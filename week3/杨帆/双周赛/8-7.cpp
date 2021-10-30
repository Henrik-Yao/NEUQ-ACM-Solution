#include<bits/stdc++.h>
using namespace std;
const int k=1000000+5;
int a[k],temp[k];
unsigned long long cnt;
void merge_sort(int l,int r){
    if(l==r)
        return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int pl=l,pr=mid+1,now=0;
    while(pl<=mid&&pr<=r){
        if(a[pl]<=a[pr])
            temp[++now]=a[pl++];
        else
            temp[++now]=a[pr++],cnt+=mid+1-pl;
    }
    while(pl<=mid)
        temp[++now]=a[pl++];
    while(pr<=r)
        temp[++now]=a[pr++];
    for(int i=l;i<=r;i++){
        a[i]=temp[i-l+1];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    merge_sort(1,n);
    printf("%lld",cnt);
    return 0;
}
