#include<bits/stdc++.h>
using namespace std;
#define MAX 65535
#define N 100
int f[N][N];
int v[N][N];
int d[N][N];
int m,n;
typedef struct xun{
    int x;
    int y;
}xun;
vector<xun> tt;
xun ss[N][N];
int h[4] = {0,1,0,-1};
int s[4] = {1,0,-1,0};
void dfs(int x1,int y1,int x2,int y2)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = MAX;
    d[x1][y1] = 0;
    queue<xun> p;
    xun q;
    q.x = x1; q.y = y1;
    p.push(q);
    v[x1][y1] = 1;
    while (!p.empty())
    {
        xun t = p.front();
        p.pop();
        for(int i = 0; i < 4; i++)
        {
            int a = t.x + h[i];
            int b = t.y + s[i];
            if(a > 0 && a < m && b > 0 && b < n && f[a][b] != -1)
            {
                xun nw;
                nw.x = a; nw.y = b;
                if(d[a][b] > d[t.x][t.y] + f[a][b])
                {
                    d[a][b] = d[t.x][t.y] + f[a][b];
                    ss[a][b].x = t.x;
                    ss[a][b].y = t.y;
                }
                if(!v[a][b]) {
                    v[a][b] = 1;
                    p.push(nw);
                }
            }
        }
    }
}
void find(int x1,int y1,int x2,int y2)
{
    if(x1==x2&&y1==y2)return ;
    xun xum = {x2,y2};
    tt.push_back(xum);
    int t1 = ss[x2][y2].x;
    int t2 = ss[x2][y2].y;
    find(x1,y1,t1,t2);
}
int main() {
    cin>>m>>n;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin>>f[i][j];
    dfs(x1,y1,x2,y2);
    find(x1,y1,x2,y2);
    for(auto it: tt)printf("(%d %d)",it.x,it.y);
    printf("(%d %d)",x1,y1);
    return 0;
}