#include<bits/stdc++.h>
using namespace std;
int a[100010],tmp[100010];
long long merge(int l, int r){
    if(l>=r) return 0;
    int mid = l+r>>1;
    long long res = merge(l,mid)+merge(mid+1,r);
    int k = 0,i = l,j = mid+1;
    while(i <= mid&&j <= r){
       if(a[i]<=a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++],res+=mid-i+1;
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i = l,j = 0;i <= r; i++,j++) a[i] = tmp[j];
     return res;
}
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    cout<<merge(0,n-1);
}
