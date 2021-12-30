#include <iostream>
using namespace std;
long long sum = 0;
int t[1000000];int s[1000000];
void p(int l,int r){
    int mid = (l+r)/2;
    int i = l;
    int j = mid + 1;
    int k = l;
    while (i<=mid&&j<=r){
        if(t[i]<=t[j]){
            s[k] = t[i];
            i++;
            k++;
        } else{
            sum = sum + mid - i + 1;
            s[k] = t[j];
            k++;
            j++;
        }
    }
    if(i==mid+1){
        while (j<=r){
            s[k] = t[j];
            k++;
            j++;
        }
    } else{
        while (i<=mid) {
            s[k] = t[i];
            i++;
            k++;
        }
    }
    for (int m = l; m <= r; ++m) {
        t[m] = s[m];
    }
}
void x(int f[],int l,int r){
    if(l == r){
        t[l] = f[r];
    } else {
        int mid = (l + r) / 2;
        x(f, l, mid);
        x(f, mid + 1, r);
        p(l, r);
    }
}
int main() {
    int n;
    cin>>n;
    int f[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&f[i]);
    }
    x(f,0,n-1);
    printf("%lld",sum);
    return 0;
}