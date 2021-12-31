#include <bits/stdc++.h>
using namespace std;

const int max_n = 500;
vector <int> p[max_n];
int ans[max_n];
bool vis[max_n];
int vexnum,arcnum;
int from,to;
int flag = 1;

int dfs(int x){
    vis[x] = true;
    if(ans[x]) return ans[x];//记忆化搜索
    for(auto i:p[x]){
        ans[x] += dfs(i);
    }
    return ans[x];
}

int main(){
    cin>>vexnum>>arcnum;
    int i;
    for(i = 0;i < arcnum;i++){
        int u;
        int v;
        cin>>u>>v;
        p[u].push_back(v);
    }
    cin>>from>>to;
    ans[to] = 1;
    cout<<dfs(from)<<' ';
    for(i = 1;i <= vexnum;i++){
        if(vis[i] && !ans[i]){
        flag = 0;
        break;
        }
    }
    if(flag)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return 0;
}