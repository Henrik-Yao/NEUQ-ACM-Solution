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
char s[_];
int n;
int main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;++i) {
        if(s[i]=='A') {
            cout<<"sae";
        } else if(s[i]=='B') {
            cout<<"tsaedsae";
        } else if(s[i]=='(') {
            int l=i+1,r=l;
            for(int j=i+1;j<=n;++j) {
                if(s[j]==')') {
                    r=j-1;
                    break;
                }
            }
            if(l>r) continue;
            for(int j=r;j>=l+1;--j) cout<<s[l]<<s[j];
            cout<<s[l];
        }
    }
    return 0;
}