#include <bits/stdc++.h>
using namespace std;
long long a[500101],temp[500101];
long long n;
long long ans=0;
void merge(long long low,long long high){
    long long mid=(low+high)>>1;
    long long pl=low,pr=mid+1,k=0;
    while(pl<=mid&&pr<=high){
        if(a[pl]<=a[pr]) temp[k++]=a[pl++];
        else temp[k++]=a[pr++],ans += mid - pl + 1;
    }
    while(pl<=mid) temp[k++]=a[pl++];
    while(pr<=high) temp[k++]=a[pr++];
    for(int i=0;i<k;i++)
        a[i+low]=temp[i];
}
void merge_sort(int low,int high){
        if(low>=high) return;
        long long mid=(low+high)>>1;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
    merge(low,high);
}
int main(){
    cin>>n;
    for(long long i=0;i<n;i++)
        cin>>a[i];
    merge_sort(0,n-1);
    cout<<ans;
}
