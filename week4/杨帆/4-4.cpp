#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll quickmod(ll a,ll b,ll c){
    ll res=1;
    while(b){
        if(b & 1){
            res = res * a % c;
        }
        a =a * a % c;
        b >>= 1;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,m,p;
        cin>>n>>m>>p;
        ll ans=quickmod(n,m,p);
        cout << ans << "\n";
    }
    return 0;
}
