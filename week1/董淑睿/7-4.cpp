#include <bits/stdc++.h>
using namespace std;
int f[2021];
int dfs(int n) {
    if(f[n]) return f[n];
    int tmp=1;
    for(int i=1;i*i<=n;++i) {
        if(n%i==0) {
            if(i!=n) tmp+=dfs(i);
            if(n/i!=i&&n/i!=n) tmp+=dfs(n/i);
        }
    }
    f[n]=tmp;
    return f[n];
}
int main() {
    int n;
    cin>>n;
    cout<<dfs(n);
    return 0;
}