#include<bits/stdc++.h>
using namespace std;
int n,m,now;
const int k=1005;
char s[k][k];
int book[k][k],a[k][2],f[k][k];
bool is(int x,int y){
    return x>0&&y>0&&x<=n&&y<=n;
}

void dfs(int x,int y){
    now++;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    a[now][0] = x;a[now][1] = y;
    for(int i = 0;i < 4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(is(tx,ty) && !book[tx][ty] && s[tx][ty]!=s[x][y]){
            book[tx][ty] = 1;
            dfs(tx,ty);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)   scanf("%s",s[i]+1);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(!book[i][j]){
                now=0;
                book[i][j]=1;
                dfs(i,j);
                for(int j = 1;j <= now;j++)
                    f[a[j][0]][a[j][1]] = now;
            }
        }
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<f[a][b];
        if(m)
            cout<<"\n";
    }
    return 0;
}


