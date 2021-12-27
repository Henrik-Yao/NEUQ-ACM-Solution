#include <bits/stdc++.h>
using namespace std;
#define maxn 1510

int F[maxn];

struct Edge{
    int u;
    int v;
    int w;
}edge[maxn];

bool cmp(Edge a,Edge b){
    return a.w < b.w;
}

int Find(int x){//找（当前作为起点的）点和（当前作为终点的）点的起点是否相同
    if(F[x] == x)
    return F[x];
    else return F[x] = Find(F[x]);
}

bool work(int a,int b){
    int x = Find(a),y = Find(b);
    if(x != y){//如果起点不相同
        F[y] = x;//就把（当前作为终点的）点的起点更新为（当前作为起点的）点
        return true;
    }
    return false;
}

int main(){
    int n,_v,e;
    while(scanf("%d%d%d",&n,&_v,&e) != EOF){
    for(int i = 0;i < e;i++){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    for(int i = 0;i < n;i++)F[i] = i;
    sort(edge,edge + e,cmp);
    int num = 0,sum = 0,cnt = 0;
    for(int i = 0;i < e;i++){
        if((edge[i].u == _v || edge[i].v == _v) && num < 2){
            if(work(edge[i].u,edge[i].v)){//如果不形成环
            sum += edge[i].w;//加上权值
            cnt++;//计数器++
            num++;
        }
        }
        else if(edge[i].u != _v && edge[i].v != _v){
            if(work(edge[i].u,edge[i].v)){//如果不形成环
            sum += edge[i].w;//加上权值
            cnt++;//计数器++
            }
            }
        if(cnt == n - 1)break;//如果已经完成生成树
    }
    if(cnt == n - 1 && num <= 2)printf("%d\n",sum);
    else puts("-1");
    }
    return 0;
}