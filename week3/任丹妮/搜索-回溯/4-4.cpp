#include <bits/stdc++.h>
using namespace std;
typedef struct pos{
    int x,y;
    pos(int a,int b):x(a),y(b){}
};
int vis[1001][1001];
int path[4][2]={{1,0},{0,1},{-1,0},{0,-1}},ans[1000001],a[1001][1001],n,m,x,y,col=0;
queue<pos>q;
int bfs(int r,int c){
    int sum=0;
    pos t1(r,c);
    q.push(t1);
    vis[r][c]=col;
    while(!q.empty()){
        pos p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int dx=p.x+path[i][0];
            int dy=p.y+path[i][1];
            if(dx<1||dx>n||dy<1||dy>n) continue;
            if(!vis[dx][dy]&&a[dx][dy]+a[p.x][p.y]==1) {
                vis[dx][dy]=col;
                pos t2(dx,dy);
                q.push(t2);
            }
        }
        sum++;
    }
    return sum;
}
int main(){
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            char c;
            cin>>c;
            a[i][j]=c-'0';
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j]){
                col++;
                ans[col]=bfs(i,j);
            }
        }
    }
    for(int i=1;i<m;i++){
        cin>>x>>y;
        cout<<ans[vis[x][y]]<<endl;
    }
    cin>>x>>y;
    cout<<ans[vis[x][y]];
    return 0;
}

