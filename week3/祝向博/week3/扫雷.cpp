#include <bits/stdc++.h>
using namespace std;

const int xx[8]={0,-1,1,0,1,-1,1,-1};
const int yy[8]={-1,0,0,1,-1,1,1,-1};

bool flg;
int N,M,K,L;
bool vis[50][50];
int a[50][50];

struct node {
    int x,y;
};
queue <node> Q;

inline int read() {
    int ret=0,f=1;char ch=getchar();
    for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
    for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
    return ret*f;
}

inline bool check(int x,int y) {
    if (x<1||x>N) return 0;
    if (y<1||y>M) return 0;
    return 1;
}

void bfs(node st) {
    if (a[st.x][st.y]==0) Q.push(st);
    vis[st.x][st.y]=1;
    while (!Q.empty()) {
        node tmp=Q.front();Q.pop();
        int &x=tmp.x,&y=tmp.y;
        vis[x][y]=1;
        for (int f=0; f<8; ++f)
            if (check(x+xx[f],y+yy[f])) {
                if (!vis[x+xx[f]][y+yy[f]]&&a[x+xx[f]][y+yy[f]]>=0) {
                    vis[x+xx[f]][y+yy[f]]=1;
                    if (a[x+xx[f]][y+yy[f]]==0) Q.push((node){x+xx[f],y+yy[f]});
                }
            }
    }
    flg=1;
    for (int i=1; i<=N; ++i,puts(""))
        for (int j=1; j<=M; ++j) {
            if (vis[i][j]) printf("%d ",a[i][j]);
            else printf("-1 ");
            if (!vis[i][j]&&a[i][j]>=0) flg=0;
        }
    if (flg) puts("You win");else puts("");
}

int main() {
    N=read(),M=read(),K=read(),L=read();
    memset(vis,0,sizeof vis);
    memset(a,0,sizeof a);
    for (int i=1; i<=K; ++i) {
        int x=read()+1,y=read()+1;
        a[x][y]=-100;
        for (int f=0; f<8; ++f)
            if (check(x+xx[f],y+yy[f])) {
                a[x+xx[f]][y+yy[f]]++;
            }
    }
    for (int i=1; i<=L; ++i) {
        int x=read()+1,y=read()+1;
        if (vis[x][y]) continue;
        if (a[x][y]<0) {
            puts("You lose");
            return 0;
        }
        bfs((node){x,y});
    }
    return 0;
}
