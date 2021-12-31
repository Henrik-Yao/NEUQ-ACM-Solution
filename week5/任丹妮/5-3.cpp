#include <bits/stdc++.h>
#define max 20001
using namespace std;
vector<int>arcs[max];
int vex[max];
bool vis[max];
void dfs(int n){
    int j=0;
    vis[n]=1;
    cout<<vex[n]<<" ";
    for(int j=0;j<arcs[n].size();j++){
        if(!vis[arcs[n][j]])
            dfs(arcs[n][j]);
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        vex[i]=i;
    while(e--){
        int a,b;
        cin>>a>>b;
        arcs[a].push_back(b);
    }
    for(int i=0;i<n;i++)
    {
        if(arcs[i].size()>1)
        sort(arcs[i].begin(),arcs[i].end());
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i);
    }
    return 0;
}
