#include <bits/stdc++.h>
using namespace std;

const int max_n = 101;
vector <int> p[max_n];
bool vis[max_n],safe[max_n];
queue <int> q;
void bfs(int v){
    while(!q.empty()){
    v = q.front();
    vis[v] = true;
    q.pop();
    for(auto i:p[v]){
        if(!safe[i] || vis[i])continue;
        q.push(i);
    }
    }
}

int main(){
    int vexnum,safenum,arcnum;
    int i,data;
    int from,to;
    cin>>vexnum>>safenum>>arcnum;
    for(i = 1;i <= safenum;i++){
        cin>>data;
        safe[data] = true;
    }
    for(i = 1;i <= arcnum;i++){
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    cin>>from>>to;
    if(!safe[to])
    cout<<"The city "<<to<<" is not safe!";
    else{
    q.push(from);
    bfs(from);
    if(vis[to])
    cout<<"The city "<<to<<" can arrive safely!";
    else
    cout<<"The city "<<to<<" can not arrive safely!";
    }
    return 0;
}

