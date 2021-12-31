#include <bits/stdc++.h>
using namespace std;
#define maxn 1001
#define inf 0x3f3f3f3f

struct node{
    int v;//尾结点
    int w;//权值
};
int n,e;
vector<node>p[maxn];//使用动态二维数组，防止爆空间和时间
int dist[maxn],vis[maxn],path[maxn];//dist为起始点到终止点的距离，vis用于判断是否被访问过，path用于存储经过的端点
void Dijkstra(int sta){
    memset(dist,inf,sizeof(dist));
    dist[sta] = 0;
    for(int i = 0;i < n;i++){
        int u = -1,_min = inf;
        for(int j = 0;j < n;j++){
            if(!vis[j] && dist[j] < _min){
                _min = dist[j];
                u = j;
            }
        }
        if(u == -1)break;
        vis[u] = 1;
        for(int j = 0,sz = p[u].size();j < sz;j++){
            int x = p[u][j].v;
            if(!vis[x] && dist[x] > dist[u] + p[u][j].w){
                dist[x] = dist[u] + p[u][j].w;
                path[x] = u;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&e);
    for(int i = 0;i < e / 2;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        p[a].push_back(node{b,c});
        p[b].push_back(node{a,c});
    }
    int sta,end;
    scanf("%d%d",&sta,&end);
    if(sta == end){
        printf("%d-->%d:0",sta,end);
        return 0;
    }
    Dijkstra(sta);
    vector<int>ans;
    int x = end;
    while(x != sta){
        ans.push_back(x);
        x = path[x];
    }
    printf("%d",sta);
    for(int i = ans.size() - 1;i >= 0;i--){
        printf("-->%d",ans[i]);
    }
    printf(":%d",dist[end]);
    return 0;
}