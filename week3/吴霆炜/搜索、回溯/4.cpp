#include <bits/stdc++.h>
using namespace std;
#define  maxINT 1001

int a[maxINT][maxINT];
int ans[maxINT][maxINT];
int temp[1000001][2];
int n,m,po;
int b[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x,int y){
    po++;
    temp[po][0] = x;
    temp[po][1] = y;
    ans[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int u = x + b[i][0];
        int v = y + b[i][1];
        if(u < 1 || u > n || v < 1 || v > n)continue;
        if(ans[u][v] > 0)continue;
        if(a[u][v] == a[x][y])continue;
        dfs(u,v);
    }
}

int main(){
    memset(ans,0,sizeof(ans));
    cin>>n>>m;
    int i,j;
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    for(i = 1;i <= m;i++){
        po = 0;
        int x,y;
        cin>>x>>y;
        if(ans[x][y] > 0){
        cout<<ans[x][y]<<endl;
        continue;
        }
        dfs(x,y);
        for(j = 1;j <= po;j++){
            ans[temp[j][0]][temp[j][1]] = po;
        }
        cout<<po<<endl;
    }    
    return 0;
}