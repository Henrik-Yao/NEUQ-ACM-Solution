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
int q_pow(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = 1ll * ans * a % c;
        a = 1ll * a * a % c;
        b >>= 1;
    } return ans; 
}
int main() {
    int T = read();
    while(T --> 0) {
        int a = read(), b = read(), c = read();
        cout << q_pow(a, b, c) << "\n";
    }
    return 0;
}