#include <bits/stdc++.h>
#define max 2002
using namespace std;
int m,n;
int Map[max][max];

void bfs(int r,int c){
    Map[r][c]=0;
    if(r>0&&Map[r-1][c]==1) bfs(r-1,c);
    if(r+1<m&&Map[r+1][c]==1) bfs(r+1,c);
    if(c>0&&Map[r][c-1]==1) bfs(r,c-1);
    if(c+1<n&&Map[r][c+1]==1) bfs(r,c+1);
}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>Map[i][j];
    int ans=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(Map[i][j]==1){
                ans++;
                bfs(i,j);
            }
    cout<<ans;
}
