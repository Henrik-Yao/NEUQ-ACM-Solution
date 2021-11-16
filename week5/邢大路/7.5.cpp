#include<bits/stdc++.h>
using namespace std;
int n;
int flag=0;
int m[10000000];
int vis[10000000];
void dfs(int now){
    if(vis[now])return;
    vis[now]=1;
    if(m[now]==0){
        flag=1;
        return;
    }
    int new1=now-m[now];
    if(new1>=0)
    dfs(new1);
    int new2=now+m[now];
    if(new2<=n-1)
    dfs(new2);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>m[i];
    }
    int start;
    cin>>start;
    dfs(start);
    if(flag)cout<<"True";
    else cout<<"False";
    return 0;
}
