#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=4e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,top;
char stak[_],s[_];
int main() {
    // freopen("a.in","r",stdin);
    while(scanf("%s",s+1)!=EOF) {
        n=strlen(s+1);
        top=0;
        for(int i=1;i<=n;++i) {
            if(s[i]==')'&&stak[top]=='(') top--;
            else stak[++top]=s[i];
        }
        if(top==0) {
            cout<<"Match\n";
        } else {
            cout<<top<<"\n";
            if(stak[1]=='(') cout<<s+1;
            for(int i=1;i<=top;++i) {
                if(stak[i]!=stak[i-1]&&i-1>=1) {
                    cout<<s+1;
                }
                if(stak[i]=='(') cout<<')';
                else cout<<'(';
            }
            if(stak[top]==')') cout<<s+1;
            cout<<"\n";
        }        
    }
    return 0;
}
/*

  ()))((
((()))(())
()()()()()(())
*/
