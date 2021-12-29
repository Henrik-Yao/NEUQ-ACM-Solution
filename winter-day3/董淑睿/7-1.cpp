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
int n,m,flag;
struct node{int a,b,c;}G[_];
bool cmp(node a,node b) {
    if(a.a==b.a) return a.b<b.b;
    else return a.a<b.a;
}
int main() {
    n=read(),m=read();
    for(int i=1;i<=m;i++) G[i].a=read(),G[i].b=read(),G[i].c=read();
    G[0].a=-1;
    sort(G+1,G+1+m,cmp);
    for(int i=1;i<=m;i++) {
        if(G[i].a!=G[i-1].a) {
            if(!flag){flag=1;printf("%d:(%d,%d,%d)",G[i].a,G[i].a,G[i].b,G[i].c);}
            else printf("\n%d:(%d,%d,%d)",G[i].a,G[i].a,G[i].b,G[i].c);
        }
        else printf("(%d,%d,%d)",G[i].a,G[i].b,G[i].c);
    }
    return 0;
}
