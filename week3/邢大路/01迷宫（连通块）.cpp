#include<bits/stdc++.h>
using namespace std;
int n,m,tot,aa,ab,sum;
int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
char ditu[1005][1005];
int vis[1005][1005];
int flag[1005][1005];
int ans[1000005];
void dfs(int x,int y){
    if(vis[x][y])return;
    vis[x][y]=1;
    sum++;
    flag[x][y]=tot;
    for(int i=1;i<=4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=n&&ditu[x][y]!=ditu[nx][ny]){
            dfs(nx,ny);
        }   
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    for(int k=1;k<=n;k++){
        cin>>ditu[i][k];
    }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j]){
                tot++;
                sum=0;
                dfs(i,j);
                ans[tot]=sum;
            }
        }
    }
    for(int i=1;i<=m;i++){
    cin>>aa>>ab;
        cout<<ans[flag[aa][ab]];
        if(i!=m)cout<<endl;	
    }
    return 0;
}
