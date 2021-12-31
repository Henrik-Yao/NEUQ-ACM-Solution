#include <bits/stdc++.h>
using namespace std;
int a[21][21],num[21][21],d[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int n,m;
bool vis[21][21];//记录是否被访问
bool dl[21][21];//记录地雷的位置
void dfs(int r,int c){//先循环周围记录雷的个数
    if(vis[r][c]) return;
    if(num[r][c]!=0) return;
    if(dl[r][c]) return;
    int dx,dy;
    for(int i=0;i<8;i++){
        dx=r+d[i][0];
        dy=c+d[i][1];
        if(dx<0||dx>=n||dy<0||dy>=m) continue;
        if(dl[dx][dy]) num[r][c]++;
    }
    a[r][c]=num[r][c];
    vis[r][c]=1;
    if(a[r][c]==0){
        for(int i=0;i<8;i++){
            dx=r+d[i][0];
            dy=c+d[i][1];
            if(dx<0||dx>=n||dy<0||dy>=m) continue;
            dfs(dx,dy);
        }
    }
}

int main(){
    int k,l,flag1=0,flag2=0;
    cin>>n>>m>>k>>l;
    memset(vis,0,sizeof(vis));
    memset(dl,0,sizeof(dl));
    memset(num,0,sizeof(num));
    memset(a,-1,sizeof(a));
    int g=k;
    while(k--){
        int i,j;
        cin>>i>>j;
        dl[i][j]=1;
    }
    while(l--){
        int r,c;
        cin>>r>>c;
        if(vis[r][c]) continue;
        else if(dl[r][c]==1) {
            cout<<"You lose"<<endl;
            flag1=1;
        }
        else if(dl[r][c]!=1){
            dfs(r,c);
            int count=0;
            for(int p=0;p<n;p++){
                for(int q=0;q<m;q++){
                     cout<<a[p][q]<<" ";
                    if(a[p][q]==-1) count++;
                }
            cout<<endl;
            }
        if(count==g) {
            cout<<"You win"<<endl;
            flag2=1;
        }
        }
        if(!flag1&&!flag2) cout<<endl;
    }
    return 0;
}
