#include <bits/stdc++.h>
using namespace std;

const int xx[4]={0,1,0,-1};
const int yy[4]={1,0,-1,0};

int N,M,TOT;
bool a[1005][1005],vis[1005][1005];
int s[1005][1005],Ans[1005][1005];

struct node {int x,y;};
queue <node> Q;

inline int read() {
    int ret=0,f=1;char ch=getchar();
    for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
    for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
    return ret*f;
}

inline bool check(int x,int y) {
    if (x<1||x>N) return 0;
    if (y<1||y>N) return 0;
    return 1;
}

void bfs(node st) {
    int cnt=0;
    Q.push(st),vis[st.x][st.y]=1;
    while (!Q.empty()) {
        node tmp=Q.front();Q.pop();
        s[tmp.x][tmp.y]=TOT;
        ++cnt;
        for (int f=0; f<4; ++f) {
            int x=tmp.x,y=tmp.y;
            if (check(x+xx[f],y+yy[f])&&a[x][y]!=a[x+xx[f]][y+yy[f]]) {
                if (!vis[x+xx[f]][y+yy[f]]) Q.push((node){x+xx[f],y+yy[f]});
                vis[x+xx[f]][y+yy[f]]=1;
            }
        }
    }
    Q.push(st),vis[st.x][st.y]=0;
    while (!Q.empty()) {
        node tmp=Q.front();Q.pop();
        Ans[tmp.x][tmp.y]=cnt;
        for (int f=0; f<4; ++f) {
            int x=tmp.x,y=tmp.y;
            if (check(x+xx[f],y+yy[f])&&a[x][y]!=a[x+xx[f]][y+yy[f]]) {
                if (vis[x+xx[f]][y+yy[f]]==1) Q.push((node){x+xx[f],y+yy[f]});
                vis[x+xx[f]][y+yy[f]]=0;
            }
        }
    }
}

int main() {
    N=read(),M=read();
    for (int i=1; i<=N; ++i,getchar())
        for (int j=1; j<=N; ++j)
            a[i][j]=(getchar()=='1'),s[i][j]=-1;
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j) if (s[i][j]==-1) ++TOT,bfs((node){i,j});
     for (int i=1; i<=M; ++i) {
         int x=read(),y=read();
         printf("%d\n",Ans[x][y]);
     }
    return 0;
}
