#include <bits/stdc++.h>
using namespace std;
#define N 101
int indegree[N];//indegree是各顶点入度
int adj[N][N];//邻接矩阵表示图
int visit[N];//记录是否访问
int n,m;//n个顶点，m条边
int result;//结果计数
void dfs(int num){
    if(num==n){//搜索结束条件是输出所有的点为止
        result++;//计数
        return;
    }
    for(int i=1;i<=n;i++){
        if((!indegree[i])&&(!visit[i])){//先找到没有被访问过的入度为0的点
            for(int j=1;j<=n;j++){
                if(adj[i][j]) indegree[j]--;//将所有以i为弧尾的弧头j的入度减一
            }
            visit[i]=1;//记录访问标志
            dfs(num+1);//接着搜索
            for(int k=1;k<=n;k++){//以下是回溯，恢复入度
                if(adj[i][k]) indegree[k]++;
            }
            visit[i]=0;//恢复未被访问标志
        }
    }
    return;
}
int main(){
    while(cin>>n>>m){
        result=0;
        memset(indegree,0,sizeof(indegree));
        memset(adj,0,sizeof(adj));
        memset(visit,0,sizeof(visit));
        while(m--){
            int a,b;
            cin>>a>>b;
            indegree[b]++;
            adj[a][b]=1;
        }
        dfs(0);
        if(result<=1) cout<<result<<endl;
        else cout<<"2"<<endl;
    }
}
