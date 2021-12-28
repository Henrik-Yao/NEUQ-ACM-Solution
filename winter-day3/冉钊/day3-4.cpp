#include<bits/stdc++.h>
using namespace std;
const int islan =1;
bool ma[110][110];
bool vst[110][110]={0};
int colo=0;
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
void dfs(int i,int j){
    vst[i][j]=1;
    for(int k=0;k<4;k++){
        int ii=i+d[k][0],jj=j+d[k][1];
        if(!vst[ii][jj]&&ii>=0&&ii<n&&jj>=0&&jj<m&&ma[ii][jj]==1)dfs(ii,jj);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>ma[i][j];
    }
    int i=0,j=0;
    while(i<n){
    if(!vst[i][j]&&ma[i][j]==1){
        vst[i][j]=1;
        colo++;
        dfs(i,j);
    }
    if(j<m)j++;
    else{
        j=0;
        i++;
    }
    }
    cout<<colo;
    return 0;
}