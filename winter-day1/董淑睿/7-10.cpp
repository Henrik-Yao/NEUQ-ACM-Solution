#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=5e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,a[_],vis[_],js;
vector<int> A[_];
int main() {
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int js=0;
    for(int i=1;i<=n;++i) {
        int las=0x3f3f3f3f;
        for(int j=1;j<=n;++j) {
            if(!vis[j]) {
                if(las>a[j]) {
                    vis[j]=1;
                    A[i].push_back(a[j]);
                    ++js;
                    las=a[j];
                }
            }
        }
        if(js==n) {
            int flag=0;
            for(auto x:A[1]) {
                if(flag==0) {
                    cout<<x;
                    flag=1;
                } else cout<<" "<<x;                
            } cout<<"\n";
            cout<<i;
            break;
        }
    }
    return 0;
}
/*
int main() {
    n=read();
    for(int i=1;i<=n;++i) a[i]=n-read()+1;
    int js=0;
    for(int i=1;i<=n;++i) {
        int l=1,r=n,dsr=0;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(b[mid]<a[i]) dsr=mid,r=mid-1;
            else l=mid+1;
        }
        if(b[dsr]==0) ++js;
        b[dsr]=a[i];
        A[dsr].push_back(a[i]);
    }
    int flag=1;
    for(auto x:A[1]) {
        if(flag) cout<<n-x+1,flag=0;
        else cout<<" "<<n-x+1;
    } cout<<"\n";
    cout<<js<<"\n";
    return 0;
}*/