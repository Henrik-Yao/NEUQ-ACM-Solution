#include <bits/stdc++.h>
using namespace std;

const int max_n = 30;
int d[8][2] = {{-1,1},{-1,0},{-1,-1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
int gre[max_n][max_n];
int a[max_n][max_n];
int n,m,k,l;

void dfs(int x, int y){
    int cnt = 0;
    for(int i = 0;i < 8;i++){
        int u = x + d[i][0];
        int v = y + d[i][1];
        if(u < 1 || u > n || v <  1 || v > m)continue;
        if(gre[u][v])
        cnt++;
    }
    a[x][y] = cnt;
    if(cnt > 0)return;
    for(int i = 0;i < 8;i++){
        int u = x + d[i][0];
        int v = y + d[i][1];
        if(u < 1 || u > n || v < 1|| v > m)continue;
        if(gre[u][v] || a[u][v] != -1)continue;
        dfs(u,v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k>>l;
    int x,y;
    memset(a,-1,sizeof(a));
    while(k--){
        cin>>x>>y;
        ++x;++y;
        gre[x][y] = 1;
    }
    while(l--){
        cin>>x>>y;
        ++x;++y;
        if(a[x][y] != -1)continue;
        if(gre[x][y]){
        cout<<"You lose"<<endl;
        return 0;
        }
        dfs(x,y);
        bool check = 1;
        for(int i = 1;i <=n;i++){
            for(int j = 1;j <= m;j++){
                    cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(!gre[i][j] && a[i][j] == -1)check = 0;
            }
        }
        if(check){
            cout<<"You win"<<endl;
            return 0;
        }
        cout<<endl;
    }
    return 0;
}