#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
struct node{
    string N;
    int G;
    bool operator < (const node &b) const {
        if(G==b.G)return N<b.N;
        return G>b.G;
    }
}p[1010];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].N>>p[i].G;
    sort(p,p+n);
    for(int i=0;i<n;i++) cout<<p[i].N<<' '<<p[i].G<<"\n";
    return 0;
}