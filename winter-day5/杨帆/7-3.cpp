 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N],b[N],c[2*N];

int main(){
    int n,i,cnt1=0,cnt2=0;
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> a[i];
    }
    for (i=0; i<n; i++) {
        cin >> b[i];
    }
    
    for (i=0; i<2*n; i++) {
        if (a[cnt1]<=b[cnt2]) {
            c[i]=a[cnt1++];
        }
        else{
            c[i]=b[cnt2++];
        }
    }
    cout << c[(2*n-1)/2] << endl;
    return 0;
    
    
}
