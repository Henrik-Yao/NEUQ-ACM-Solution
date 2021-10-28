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
int n,m,k,l,ma[100][100],mine[100][100];
int f(int x,int y) {
    int ans=0;
    for(int i=-1;i<=1;++i) {
        for(int j=-1;j<=1;++j) {
            if(i==0&&j==0) continue;
            int nx=x+i,ny=y+j;
            if(0<=nx&&nx<n&&0<=ny&&ny<m)
                ans+=mine[nx][ny];
        }
    }
    return ans;
}
int main() {
    // freopen("aa.in","r",stdin);
    n=read(),m=read();
    k=read(),l=read();
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            ma[i][j]=-1;
        }
    }
    for(int i=1;i<=k;++i) mine[read()][read()]=1;
    while(l-->0) {
        int x=read(),y=read();
        if(ma[x][y]!=-1) continue;
        if(mine[x][y]) {
            puts("You lose");
            break;
        }
        queue<pair<int,int> > q;
        q.push(make_pair(x,y));
        while(!q.empty()) {
            pair<int,int> tmp=q.front();
            q.pop();
            if(ma[tmp.first][tmp.second]!=-1) continue;
            ma[tmp.first][tmp.second]=f(tmp.first,tmp.second);
            if(ma[tmp.first][tmp.second]==0) {
                for(int i=-1;i<=1;++i) for(int j=-1;j<=1;++j) {
                    if(i==0&&j==0) continue;
                    int nx=tmp.first+i,ny=tmp.second+j;
                    if(0<=nx&&nx<n&&0<=ny&&ny<m&&ma[nx][ny]==-1) {
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        int gs=0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                printf("%d ",ma[i][j]);
                gs+=(ma[i][j]!=-1);
            }
            printf("\n");
        }
        if(n*m-gs==k) {
            printf("You win\n");
            break;
        }
        cout<<"\n";
    }
    return 0;
}