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
int n,top;
char s[_],stak[_];
int main() {
    cin>>(s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;++i) {
        if(n&1 and i==n/2+1) continue;
        if(stak[top]==s[i]) top--;
        else stak[++top]=s[i];
    }
    if(top) cout<<"no";
    else cout<<"yes";
    return 0;
}