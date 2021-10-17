#include <bits/stdc++.h>
using namespace std;
const int _=1e3;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
char a[3][_];
void f(int x,int now,int goal) {
    if(x==1) {
        if(now!=goal) printf("%s->%s\n",a[now],a[goal]);
        return;
    }
    f(x-1,now,3-now-goal);
    printf("%s->%s\n",a[now],a[goal]);
    f(x-1,3-now-goal,goal);
}
int main() {
    int n=read();
    cin>>a[0]>>a[1]>>a[2];
    f(n,0,2);
    return 0;
}