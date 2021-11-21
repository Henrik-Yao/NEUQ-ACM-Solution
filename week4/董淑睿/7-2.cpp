#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
ll f[1000];
int main() {
    f[2] = 1;
    f[3] = 2;
    int T = read();
    for(int i = 4; i <= 40; ++i) f[i] = f[i - 1] + f[i - 2];
    while(T --> 0) {
        cout << f[read()];
        if(T != 0) cout << "\n";
    }
    return 0;
}