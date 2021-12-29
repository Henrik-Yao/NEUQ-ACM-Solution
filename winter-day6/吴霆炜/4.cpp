//归并排序求逆序对
#include <bits/stdc++.h>
using namespace std;
#define int long long//注意要开long long，不然会爆

vector<int>a,b;
int n,ans;
void merge_sort(int l,int r){
    if(l == r)return;
    int m = (l + r) >> 1;
    merge_sort(l,m);
    merge_sort(m + 1,r);
    int i = l,j = m + 1,k = l;
    while(i <= m && j <= r){
        if(a[i] <= a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
            ans += m - i + 1;
        }
    }
    while(i <= m)
        b[k++] = a[i++];
    while(j <= r)
        b[k++] = a[j++];
    for(int p = l;p <= r;p++)
        a[p] = b[p];
}
signed main(){
    // freopen("data.txt","r",stdin);
    scanf("%lld",&n);
    a.resize(n + 1);b.resize(n + 1);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    merge_sort(1,n);
    printf("%lld\n",ans);
    return 0;
}