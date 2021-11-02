#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 10000000

ll cnt;
bool v[maxn];

void prime(ll x){
    for(ll i = 2;i <= x;i++){
        if(v[i])continue;
        cnt++;
        for(ll j = i;j <= x / i;j++){
            v[i * j] = 1;
        }
    }
}

int main(){
    ll n;
    cin>>n;
    prime(n);
    cout<<cnt<<endl;
    return 0;
}