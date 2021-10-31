#include<iostream>
using namespace std;
int vis[600], step[600],vec[600][600];
int n, m, sum, a, b;
int DFS(int x) {
    vis[x] = 1;
    if(step[x]) return step[x];
    for(int i=1;i<=n;i++)
        if(vec[x][i])
            step[x] += DFS(i);
    return step[x];
}
int main(){
    int i;
    cin>>n>>m;
    for(i=1;i<=m;i++) {
        cin>>a>>b;
        vec[a][b]=1;
    }
    cin>>a>>b;
    step[b] = 1;
    sum = DFS(a);
    int flag = 1;
    for(i=1;i<=n;i++) {
        if(vis[i] && !step[i]) {
            flag = 0;
            break;
        }
    }
    cout<<sum<<" ";
    if(!flag)
        cout<<"No";
    else
        cout<<"Yes";
}
