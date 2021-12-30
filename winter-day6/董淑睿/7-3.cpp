#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
map<int,int>dsr;
int main(){
    int n=read();
    for(int i=1;i<=n;++i) {
        int tmp=read();
        dsr[tmp]++;
    }
    for(auto x:dsr) printf("%d:%d\n",x.first,x.second);
    return 0;
}