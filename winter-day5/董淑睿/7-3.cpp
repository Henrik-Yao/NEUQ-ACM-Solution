#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n;
int main() {
    int n=read();
    vector<int> a;
    for(int i=1;i<=n+n;++i) {
        int tmp=read();
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    cout<<a[((int)a.size()-1)/2];
    return 0;
}