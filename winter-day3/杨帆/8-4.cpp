#include<bits/stdc++.h>
using namespace std;
const int k = 1e2+10;
int map_[k][k];
bool vis[k][k];
int n,m;

bool is(int x,int y){
    if(x<=n && y<=m && x>0 && y>0){
        return true;
    }
    else{
        return false;
    }
}

void dfs(int x,int y){
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    for(int i=0; i<4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(is(tx,ty) && !vis[tx][ty] && map_[tx][ty] == 1){
            vis[tx][ty] = 1;
            dfs(tx,ty);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map_[i][j];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map_[i][j] == 1 && !vis[i][j]){
                ans++;
                vis[i][j] = 1;
                dfs(i,j);
            }
        }
    }
    cout << ans;
}
