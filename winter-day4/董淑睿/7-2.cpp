#include <bits/stdc++.h>
using namespace std;
const int _=1e3+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
int n,m,dis[1000][1000];
int main() {
    while(cin>>n>>m) {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j]=1000000000;
        for(int i=1;i<=n;++i) {
            int x=read()+1,num=read();
            while(num--) {
                int y=read()+1;
                dis[x][y]=1;
                // cout<<x<<" "<<y<<"\n";
            }
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        while(m--) {
            int x=read()+1,y=read()+1;
            if(dis[x][y]==1000000000) cout<<"connection impossible\n";
            else cout<<dis[x][y]<<"\n";
        }
    } 
    return 0;
}
