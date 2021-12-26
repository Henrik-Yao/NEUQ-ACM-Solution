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
char stak[_];
map<char,char> m;
int main() {
    // freopen("a.in","r",stdin);
    char s=0;
    m[')']='(';
    m[']']='[';
    m['}']='{';
    while((s=getchar())!=EOF) {
        if(s=='{'||s=='['||s=='(') {
            stak[++top]=s;
        } else {
            if(m.count(s)==0) continue;
            if(stak[top]==m[s]) {
                top--;
            } else stak[++top]=s;
        }
        // for(int i=1;i<=top;++i) cout<<stak[i]<<" ";cout<<"\n";
    }
    if(top) cout<<"no";
    else cout<<"yes";
    return 0;
}