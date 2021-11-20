#include<bits/stdc++.h>
using namespace std;
const int k = 2005;
bool vis[k][k];
int site[k*k][2],mp[k][k];
int n,m;

bool is(int x,int y){
    return x>0&&y>0&&x<=n&&y<=m;
}
void dfs(int x,int y){
    int xx[] = {1,0,0,-1};
    int yy[] = {0,1,-1,0};
    for(int i=0; i<4; i++){
        int tx = x + xx[i];
        int ty = y + yy[i];
        if(mp[tx][ty] == 1 && !vis[tx][ty] && is(tx,ty)){
            vis[tx][ty] = 1;
            dfs(tx,ty);
        }
    }
}

int main(){
    cin >> n >> m;
    int p = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mp[i][j];
            if(mp[i][j]){
                site[++p][0] = i;
                site[p][1] = j;
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=p; i++){
        if(!vis[site[i][0]][site[i][1]]){
            ans++;
            vis[site[i][0]][site[i][1]] = 1;
            dfs(site[i][0],site[i][1]);
        }
    }
    cout << ans;
    return 0;
}
