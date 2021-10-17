#include <bits/stdc++.h>
using namespace std;
const int _=1e5+7;
int fx[_];
char s[_][20];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        scanf("%d%s",&fx[i],s[i]);
    int now=0;
    while(m-->0) {
        int x,y;
        scanf("%d%d",&x,&y);
        if(fx[now]==0) {
            if(x==0) {
                now-=y;
            } else {
                now+=y;
            }
        } else {
            if(x==0) {
                now+=y;
            } else {
                now-=y;
            }
        }
        now=(now%n+n)%n;
    }
    cout<<s[now];
    return 0;
}