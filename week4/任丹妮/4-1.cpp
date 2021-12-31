#include <bits/stdc++.h>
using namespace std;
    bool is[10002];
    vector<int>primes;
void sushu(int n){
    memset(is,0,sizeof(is));
    for(int i=2;i<=n;i++){
        if(!is[i])
            primes.push_back(i);
        for(int p:primes){
            if(p*i>n)
                break;
            is[p*i]=1;
            if(i%p==0) break;
        }
    }
}
int main(){
    int a,b,n=10000;
    sushu(n);
    while(cin>>a>>b){
        int end=-1e9;
        for(int i=0;i<primes.size();i++){
            if(primes[i]<=b) end=max(end,primes[i]);
        }
        for(int i=0;primes[i]!=end;i++){
            if(primes[i]>=a&&primes[i]<=b) cout<<primes[i]<<' ';
        }
        cout<<end<<endl;
    }
    return 0;
}
