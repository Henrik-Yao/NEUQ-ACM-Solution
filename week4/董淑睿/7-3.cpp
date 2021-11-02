#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e7+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n, vis[_], pri[_], cnt;
int main() {
    cin >> n;
    for(int i = 2; i <= n; ++i) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= n; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    cout << cnt <<"\n";
    return 0;
}