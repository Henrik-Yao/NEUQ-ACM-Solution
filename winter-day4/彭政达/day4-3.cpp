/*
7-3 ���·��֮Dijkstra
����ĿҪ��ͨ�������������ıߵ���Ϣ��ʡ���˸��������Ϣ�����ö���������ʾ��������ͼ��
������Dijkstra�㷨�����ָ��Դ�㵽������������·����
��������:
��һ�У�����������������vN�ͱ���eN�� �Ժ������У�����رߵ���Ϣ������ͼ�ı��ǶԳƵģ�
ֻ����һ��ıߣ�С��ŵ����ŵģ����Կո񣩣�������и�һ��������ǰһ��ָ��Դ�㣬
��һ��ָ���Ĳ�ѯ���յ��㡣 ��ע�⣬ʾ����34���ߣ�ֻ������17���ߵ���Ϣ��
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
�������:
��һ���������Դ�㵽ָ���յ�Ķ�·�������ۣ�ע�⣺���з��ž�Ϊ���ķ��š�
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
