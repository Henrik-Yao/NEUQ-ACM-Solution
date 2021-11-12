#include <bits/stdc++.h>
using namespace std;
long long fp(long long base,long long power,long long mod){
    long long result=1;
    while(power>0){
        if(power&1)
        result=result*base%mod;
        power>>=1;
        base=(base*base)%mod;
    }
    return result;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        long long A,B,C;
        cin>>A>>B>>C;
        cout<<fp(A,B,C)<<endl;
    }
}
