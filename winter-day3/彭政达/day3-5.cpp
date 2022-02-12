/*
7-5 繁忙的都市
城市 C 是一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造。
城市 C 的道路是这样分布的：城市中有 n 个交叉路口，有些交叉路口之间有道路相连，
两个交叉路口之间最多有一条道路相连接。这些道路是双向的，
且把所有的交叉路口直接或间接的连接起来了。每条道路都有一个分值，分值越小表示这个道路越繁忙，
越需要进行改造。但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：
改造的那些道路能够把所有的交叉路口直接或间接的连通起来。
在满足要求 (1) 的情况下，改造的道路尽量少。
在满足要求 (1)、(2) 的情况下，改造的那些道路中分值最大的道路分值尽量小。
任务：作为市规划局的你，应当作出最佳的决策，选择那些道路应当被修建。
输入格式:
第一行有两个整数 n,m 表示城市有 n 个交叉路口，m 条道路。
接下来 m 行是对每条道路的描述，u,v,c 表示交叉路口 u 和 v 之间有道路相连，分值为 c 。
输出格式:
两个整数 s,max，表示你选出了几条道路，分值最大的那条道路的分值是多少。
输入样例:
4 5
1 2 3
1 4 5
2 4 7
2 3 6
3 4 8
输出样例:
3 6
数据范围与提示
1≤n≤300,1≤c≤10000
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,cp,total,fa[10010],b[10010],s=0;
struct node{
    int x,y;
}a[10010];
struct p{
    int from,to,weight;
}e[10010];
bool cmp(p a,p b){
    return a.weight<b.weight;
}
int find(int x){
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
int main(){
    freopen("in5.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) cin>>e[i].from>>e[i].to>>e[i].weight;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++){
        int x=find(e[i].from),y=find(e[i].to);
        if(x==y) continue;
        s=e[i].weight; 
        fa[x]=y; total++;
        if(total==(n-1)) break;
    }
    cout<<n-1<<" "<<s;
}
