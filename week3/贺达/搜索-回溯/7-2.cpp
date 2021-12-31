#include<bits/stdc++.h>
using namespace std;

int vis[510];
int path[510];
int vec[510][510];
int a,b,m,n;
int cnt=0;
int DFS(int x)
{
    vis[x] = 1;
    if(path[x])
    {
        return path[x];
    }
    for(int i=1;i<=n;i++)
        if(vec[x][i])
        {
           path[x] = path[x]+DFS(i);
        }

        return path[x];
}

int main(){
    int i;
    cin>>n>>m;

    for(i=1;i<=m;i++) {
        cin>>a;
        cin>>b;

        vec[a][b]=1;
    }
    cin>>a>>b;
    path[b] = 1;
    cnt = DFS(a);
    int flag = 1;
    for(i=1;i<=n;i++)
    {
        if(vis[i] && !path[i])
        {
            flag = 0;
            break;
        }
    }
    cout<<cnt<<" ";
    if(!flag)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}
