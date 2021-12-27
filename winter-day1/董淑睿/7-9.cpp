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
int n,m;
map<string,int> bel;
struct node {
    node(string a="",int b=0,int c=0,int d=0):name(a),T(b),P(c),i(d){}
    string name;
    int T,P,i;
    bool operator < (const node &b) const {
        if(T==b.T) return i<b.i;
        return T<b.T;
    }
}a[_];
int END[_],stak[_],top,fri[_],tim[_],vis[_];
vector<int> G[_];
int main() {
    // freopen("a.in","r",stdin);
    n=read(),m=read();
    for(int i=1;i<=m;++i) {
        int gs=read();
        for(int j=1;j<=gs;++j) {
            string tmp;
            cin>>tmp;
            bel[tmp]=i;
        }
    }
    for(int i=1;i<=n;++i) {
        string tmp;
        cin>>tmp;
        int T=read(),P=min(read(),60);
        a[i]=node(tmp,T,P,i);
    }
    int time=a[1].T;
    for(int i=1,j=1;i<=n;++i) {
        if(vis[i]) continue;
        time=max(time,a[i].T);
        // cout<<i<<"!\n";
        for(;j<=n;++j) {
            if(time+tim[i]>=a[j].T) {
                if(bel.count(a[j].name)==0) {tim[j]=a[j].P,G[j].push_back(j);continue;}
                if(fri[bel[a[j].name]]==0) fri[bel[a[j].name]]=j;
                tim[fri[bel[a[j].name]]]+=a[j].P;
                G[fri[bel[a[j].name]]].push_back(j);
            } else break;
        }
        int tmp=0;
        for(auto x:G[i]) {
            vis[x]=1;
            stak[++top]=x;
            END[top]=time+tmp;
            tmp+=a[x].P;
        }
        fri[bel[a[i].name]]=0;
        time+=tim[i];
    }
    double tot=0;
    for(int i=1;i<=n;++i) {
        cout<<a[stak[i]].name<<"\n";
        // cout<<END[i]-a[stak[i]].T<<" ";
        tot+=END[i]-a[stak[i]].T;
    }
    tot/=n;
    printf("%.1f",tot);
    return 0;
}
/*
6 2
3 ANN BOB JOE
2 JIM ZOE
ANN 0 5
BOB 5 5
JIM 43424 5
ZOE 24344 2334
AMY 423 42344
JOE 34234 23524
*/