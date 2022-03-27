#include <iostream>

using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int f[m];
    for (int i = 0; i < m; ++i) {
        cin>>f[i];
    }
    int l = 0,r = m - 1;
    int mid;
    while (l!=r&&r-l>1){
        mid = (l+r)/2;
        if(f[mid]<n)l = mid;
        else r = mid;
    }
    if(f[l]>=n)cout<<l+1<<endl;
    else if(f[r]>=n)cout<<r+1<<endl;
    else cout<<m+1<<endl;
    return 0;
}