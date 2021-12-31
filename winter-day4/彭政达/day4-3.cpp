/*
7-3 最短路径之Dijkstra
本题目要求通过读入无向网的边的信息（省略了各顶点的信息，仅用顶点编号来表示），构造图，
并利用Dijkstra算法，求出指定源点到其它各点的最短路径。
输入样例:
第一行，两个整数，顶点数vN和边数eN。 以后若干行，是相关边的信息，无向图的边是对称的，
只输入一半的边（小编号到大编号的，间以空格），最后两行各一个整数，前一个指定源点，
后一个指定的查询的终到点。 （注意，示例中34条边，只输入了17条边的信息）
10 34
0 1 2
0 3 5
1 2 5
1 3 2
2 4 8
2 5 4
3 5 4
3 6 2
4 7 5
4 5 2
5 6 3
5 7 9
5 8 7
6 8 7
7 8 3
7 9 4
8 9 8
0
8
输出样例:
在一行中输出从源点到指定终点的短路径及代价，注意：所有符号均为西文符号。
0-->1-->3-->6-->8:13
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 10000
struct node{
    int v,w;
};
int vertex,edge;
vector<node> p[1010];
int dis[1010],visited[1010],path[1010];
void Dijkstra(int start){
    memset(dis,INF,sizeof(dis));
    dis[sta]=0;
    for(int i=0;i<vertex;i++){
        int u=-1,minm=INF;
        for(int j=0;j<vertex;j++)
            if(!visited[j] && dis[j]<minm){
                minm=dis[j];
                u=j;
            }
        if(u==-1) break;
        visited[u]=1;
        for(int j=0,sz=p[u].size();j<sz;j++){
            int x=p[u][j].v;
            if(!visited[x] && dis[x]>dis[u]+p[u][j].w){
                dis[x]=dis[u]+p[u][j].w;
                path[x]=u;
            }
        }
    }
}
int main(){
	freopen("in3.txt","r",stdin);
    cin>>vertex>>edge;
    for(int i=0;i<edge/2;i++){
        int a,b,c;
        cin>>b>>a>>c;
        p[a].push_back({a,c});
        p[b].push_back({b,c});
    }
    int start,end;
    cin>>start>>end;
    if(start==end){
        cout<<start<<"-->"<<end<<":0";
        return 0;
    }
    Dijkstra(start);
    vector<int> ans;
    int x=end;
    while(x!=start){
        ans.push_back(x);
        x = path[x];
    }
    cout<<start;
    for(int i=ans.size()-1;i>=0;i--) cout<<"-->"<<ans[i];
    cout<<":"<<dis[end];
}
