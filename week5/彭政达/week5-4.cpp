#include<bits/stdc++.h>
using namespace std;
#define file_in freopen("in.txt","r",stdin)
#define file_out freopen("out.txt","w",stdout)
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int n,m,i,j,num=0;
int land[2005][2005];
void dfs(int x,int y){
    land[x][y]=0;
    for(i=0;i<4;i++){
        int ax=x+dx[i],ay=y+dy[i];
        if(ax>=0 && ax<=n && ay>=0 && ay<=m && a[ax][ay]) dfs(nx,ny);
    }
}
int main(){
	ios::sync_with_stdio(false);
	file_in;
	file_out;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
         cin>>land[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(!land[i][j])
				continue;
            dfs(i,j);
            num++;
        }
    cout<<num;
    return 0;
}
