#include<bits/stdc++.h>
using namespace std;
int ditu[11000][11000];
int vis[10000][10000];
int mx[]={0,1,-1,0,0},my[]={0,0,0,1,-1};
int m,n;
void dfs(int x,int y){
    if(vis[x][y]||ditu[x][y]==0)return;
    vis[x][y]=1;
    for(int i=1;i<=4;i++){
        int xx=x+mx[i];
        int yy=y+my[i];
        if(xx>=0&&yy>=0&&xx<m&&yy<n){
            dfs(xx,yy);
        }
    }
}
int main(){
    cin>>m>>n;
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>ditu[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(ditu[i][j]==1&&vis[i][j]==0){
                count++;
                dfs(i,j);
            }
        }
    }
    cout<<count;
    return 0;
}
