#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll Mode(ll a,ll b,ll mode){
    ll sum = 1;
    while(b){
        if(b & 1){
            sum = (sum * a) % mode;
            b--;
        }
        b >>= 1;
        a =  a * a % mode;
    }
    return sum;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        ll a;ll b;ll m;
        cin>>a>>b>>m;
        cout<<Mode(a,b,m)<<endl;
    }
    return 0;
}