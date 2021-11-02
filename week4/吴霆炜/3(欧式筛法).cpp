#include <bits/stdc++.h>
using namespace std;
#define maxn 100000001
#define ll long long

bool v[maxn];
ll prime[maxn];
ll cnt,n;

int main(){
    cin>>n;
    int i,j;
    for(i = 2;i <= n;i++){
        if(!v[i])
        prime[++cnt] = i;
        for(j = 1;j <= cnt && i * prime[j] <= n;j++){
            v[i * prime[j]] = true;
            if(i % prime[j] == 0)
            break;
        }
    }
    cout<<cnt<<endl;
    return 0;
}