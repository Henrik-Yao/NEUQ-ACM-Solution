#include <bits/stdc++.h>
using namespace std;
int w[1001];
int v[1001];
int f[1600];
int main() {
    int n,c;
    while(cin>>n>>c){
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        memset(f,0,sizeof(f));
    for (int i = 1; i <= n; i++) {
        cin >> w[i] ;
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i] ;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = c; j >= 1; j--) {
            if (w[i] <= j) {
                f[j] = f[j] > f[j - w[i]] + v[i] ? f[j] : f[j - w[i]] + v[i];
            }
        }
    }
    cout << f[c] << endl;
    }
}
