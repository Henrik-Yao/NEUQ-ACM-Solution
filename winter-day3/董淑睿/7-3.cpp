#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,a[453];
int main() {
    int n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    map<vector<int>,int> dsr;
    for(int i=1;i<(1<<n);++i) {
        vector<int> x,y;
        for(int j=0;j<n;++j)
            if((1<<j)&i) {
                x.push_back(a[j+1]);
                y.push_back(a[j+1]);
            }
        sort(x.begin(),x.end());
        if(x.size()>=2&&x==y) {
            dsr[x]=1;
        }
    }
    cout<<dsr.size()<<"\n";
    return 0;
}