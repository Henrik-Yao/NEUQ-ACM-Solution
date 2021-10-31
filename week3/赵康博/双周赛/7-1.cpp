#include <iostream>

using namespace std;
int p(int l,int r,int f[]){
    if(l==r)return f[l];
    int mid = (r+l)/2;
    int ls = p(l,mid,f);
    int rs = p(mid+1,r,f);
    int sum1 = 0,t = 0,sum2 = 0;
    for (int i = mid; i >= l; --i) {
        t = t + f[i];
        sum1 = max(sum1,t);
    }
    t = 0;
    for (int i = mid+1; i <= r; ++i) {
        t = t + f[i];
        sum2 = max(sum2,t);
    }
    int maxn;
    maxn = max(max(0,sum1+sum2),max(ls,rs));
    return maxn;
}
int main(){
    int n;
    cin>>n;
    int f[n];
    for (int i = 0; i < n; ++i) {
        cin>>f[i];
    }
    cout<<p(0,n-1,f)<<endl;
    return 0;
}