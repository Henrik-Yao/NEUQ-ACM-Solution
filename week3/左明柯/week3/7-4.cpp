#include <bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
    point(int a,int b):x(a),y(b){}
};
const int maxn=1000+5;
char smap[maxn][maxn];
int d[8]={0,1,0,-1,1,0,-1,0};
int mem[maxn][maxn];
int n,m,i,j;
int ans[maxn*100]={0};
int bfs(int x,int y,int t)
{
    int cou=1;
    queue<point> q;
    point p(x,y);
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(i=0;i<8;i+=2)
        {
            int tx=p.x+d[i];
            int ty=p.y+d[i+1];
            if(tx>0&&tx<=n&&ty>0&&ty<=n&&smap[p.x][p.y]!=smap[tx][ty]&&mem[tx][ty]==0)
            {
                point p1(tx,ty);
                q.push(p1);
                mem[tx][ty]=t;
                cou++;
            }
        }
    }
    return cou;
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>smap[i]+1;
    for(int k=1;k<=m;k++)
    {
        int x,y;
        cin>>x>>y;
        if(!mem[x][y]){
            mem[x][y]=k;
            ans[k]=bfs(x,y,k);
            cout<<ans[k]<<endl;
        }
        else//被搜索过的话，直接输出结果
        {
            int t=mem[x][y];
            ans[m]=ans[t];
            cout<<ans[m]<<endl;
        }
    }
    return 0;
}
