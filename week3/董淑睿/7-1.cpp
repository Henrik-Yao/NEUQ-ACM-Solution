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
char s[3][100];
void f(int n,int now,int goal) {
    if(n==1) {
        if(now!=goal)
            cout<<s[now]<<"->"<<s[goal]<<"\n";
        return;
    }
    f(n-1,now,3-now-goal);
    cout<<s[now]<<"->"<<s[goal]<<"\n";
    f(n-1,3-now-goal,goal);
}
int main() {
    int n=read();
    for(int i=0;i<3;++i) cin>>s[i];
    f(n,0,2);
    return 0;
}