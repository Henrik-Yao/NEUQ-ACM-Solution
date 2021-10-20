#include <iostream>
using namespace std;
void PoiXau(int a[],int s[],int left,int right,int mid){
    int i = left;
    int m = mid;
    m++;
    int k = left;
    while (i<=mid&&m<=right){
        if(a[i]<a[m]){
            s[k] = a[i];
            k++;
            i++;
        } else{
            s[k] = a[m];
            k++;
            m++;
        }
    }
    if(i==mid+1){
        for (int j = m; j <= right; ++j,k++) {
            s[k] = a[j];
        }
    } else{
        for (int j = i; j <= mid; ++j,k++) {
            s[k] = a[j];
        }
    }
}
void Diuig(int a[],int s[],int left,int right){
    if(left == right){
        s[left] = a[right];
    } else{
        int mid = (right+left)/2;
        int t[200000];
        Diuig(a,t,left,mid);
        Diuig(a,t,mid+1,right);
        PoiXau(t,s,left,right,mid);
    }
}
int main() {
    int n;
    cin>>n;
    int f[n];
    for (int i = 0; i < n; ++i) {
        cin>>f[i];
    }
    int t[n];
    Diuig(f,t,0,n-1);
    for (int i = 0; i < n;++i) {
        cout<<t[i]<<" ";
    }
    return 0;
}
