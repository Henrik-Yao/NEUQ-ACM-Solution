#include <bits/stdc++.h>
using namespace std;
#define N 70
#define ll long long

ll f[N],g[N];
int main(){
    ios::sync_with_stdio(false);
    int i,j,k;
    ll inf = 0x7ffffffff;
    f[0] = 0;
    for(i = 1;i <= 63;i++)
    f[i] = 2 * (f[i - 1] + 1) - 1;
    fill(g + 1,g + 66,inf);
    g[1] = 1;
    g[2] = 3;
    for(j = 3;j <= 64;j++){
        for(k = 1;k < j;k++){
            if(j == 64 && k == 1)continue;
            g[j] = min(g[j] , 2 * g[k] + f[j - k]);
        }
    }
    int n;
    while(cin>>n){
    cout<<g[n]<<endl;
    }
    return 0;
}