#include<bits/stdc++.h>
using namespace std;
int star[1][2],en[1][2];
const int MAXN=2021;
const int INF=65535;
int N,M;
int mp[MAXN][MAXN];
int s[MAXN][MAXN];//dij算法，记录最少能量
bool vst[MAXN][MAXN]={0};
const int d[4][2]={0,1,0,-1,1,0,-1,0};
struct node{
    int x,y;
};
bool check(int x,int y){
    if(x<0||x>=N||y<0||y>M||mp[x][y]==-1) return 0;
    else return 1;
}
void bfs(int sx,int sy){
    queue<node>q;
    node sta;
    sta.x=sx;
    sta.y=sy;
    q.push(sta);
    while(!q.empty()){
        sta=q.front();
        q.pop();
        vst[sta.x][sta.y]=1;
        for(int i=0;i<4;i++){
            int xx=sta.x+d[i][0],yy=sta.y+d[i][1];
            if(check(xx,yy)&&!vst[xx][yy]){
                vst[xx][yy]=1;
                s[xx][yy]+=s[sta.x][sta.y];
                node next;
                next.x=xx;
                next.y=yy;
                q.push(next);
            }
        }
    }
}
void dayin(int enx,int eny,int sx,int sy){
    int minn=INF,ansx,ansy;
    printf("(%d %d)",enx,eny);
    if(enx==sx&&eny==sy)return;
    for(int i=0;i<4;i++){
        int xx=enx+d[i][0],yy=eny+d[i][1];
        if(minn>s[xx][yy]&&check(xx,yy)){
            minn=s[xx][yy];
            ansx=xx;
            ansy=yy;
        }
    }
    dayin(ansx,ansy,sx,sy);
}
int main(){
    memset(mp,-1,sizeof(mp));
    scanf("%d %d",&M,&N);
    scanf("%d %d %d %d",&star[0][0],&star[0][1],&en[0][0],&en[0][1]);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&mp[i][j]);
            s[i][j]=mp[i][j];
            if(mp[i][j]==-1)vst[i][j]=1;
        }
    }
    /*for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        printf("%d ",mp[i][j]);
    }
    cout<<endl;
    }*/
    bfs(star[0][0],star[0][1]);
    dayin(en[0][0],en[0][1],star[0][0],star[0][1]);
    return 0;
}