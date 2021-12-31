/*
 * @Author: ComplexPug
 * @Email: 3010651817@qq.com
 * @Date: 2021-12-25 08:11:13
 * @LastEditTime: 2021-12-25 08:12:28
 */
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
struct node {
    int val,nxt;
}a[_];
int tmp=1;
int b[_],n;
int main() {
    // freopen("a.in","r",stdin);
    int dsrdsr;
    while(scanf("%d",&dsrdsr)!=EOF) b[++n]=dsrdsr;
    sort(b+1,b+1+n);
    int now=1;
    for(int i=1;i<=n;++i) {
        dsrdsr=b[i];
        a[now].nxt=++tmp;
        a[tmp].val=dsrdsr;
        now=tmp;
    }
    for(int i=a[1].nxt;i;i=a[i].nxt) {
        if(i==a[1].nxt) cout<<a[i].val;
        else cout<<"->"<<a[i].val;
    } cout<<"\n";

    int x=++tmp,y=++tmp;
    int Hx=x,Hy=y;
    for(int i=a[1].nxt;i;i=a[i].nxt) {
        if(a[i].val%2) {
            a[x].nxt=++tmp;
            a[tmp].val=a[i].val;
            x=tmp;       
        } else {
            a[y].nxt=++tmp;
            a[tmp].val=a[i].val;
            y=tmp;       
        }
    }
    for(int i=a[Hx].nxt;i;i=a[i].nxt) {
        if(i==a[Hx].nxt) cout<<a[i].val;
        else cout<<"->"<<a[i].val;
    } cout<<"\n";
    for(int i=a[Hy].nxt;i;i=a[i].nxt) {
        if(i==a[Hy].nxt) cout<<a[i].val;
        else cout<<"->"<<a[i].val;
    } cout<<"\n";
    return 0;
}