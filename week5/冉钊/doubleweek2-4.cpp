#include<iostream>
using namespace std;
bool mmap[2001][2001],vst[2001][2001]={0};
int cnt=0,same[2001][2001]={0};
int m,n,x,y,xx,yy;
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int x,int y,int flag){
    vst[x][y]=1;
    same[x][y]=cnt;
    for(int i=0;i<4;i++){
         xx=x+d[i][0];yy=y+d[i][1];
         if(xx<1||xx>m||yy<1||yy>n||mmap[xx][yy]!=flag){
             vst[xx][yy]=1;
             continue;
         }
         if(!vst[xx][yy]){
             bfs(xx,yy,mmap[xx][yy]);
         }
    }


}
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
           cin>>mmap[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(!vst[i][j]&&mmap[i][j]==1){
                cnt++;
                bfs(i,j,mmap[i][j]);
            }
        }
    }
    cout<<cnt;

}