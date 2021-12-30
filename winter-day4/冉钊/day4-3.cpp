#include<bits/stdc++.h>
using namespace std;
const int INF=10010;
struct node{
    int en,len;//en=路的尾节点，路的长度
};
int n,e,start,stop;
vector<node>v[1010];
//动态二维数组
int dij[1010],path[1010],vst[1010];
void DIJ(int start){
    memset(dij,INF,sizeof(dij));
    dij[start]=0;
    for(int i=0;i<n;i++){
        int u=-1,minx=INF;
        for(int j=0;j<n;j++){
            if(vst[j]==0&&dij[j]<minx){
                minx=dij[j];
                u=j;
            }
        }
    
    if(u==-1) break;
    vst[u]=1;
    for(int j=0;j<v[u].size();j++){
        int x=v[u][j].en;
        if(vst[x]==0&&dij[u]+v[u][j].len<dij[x]){
            dij[x]=dij[u]+v[u][j].len;
            path[x]=u;
        }
    }
    }
}
int main(){
    cin>>n>>e;
    for(int i=0;i<e/2;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(node{b,c});
        v[b].push_back(node{a,c});
    }
    cin>>start>>stop;
    if(start==stop){
        printf("%d-->%d:0",start,stop);
        return 0;
    }//如果自己就是终点
    DIJ(start);
    vector<int >ve;
    int x=stop;
    while(x!=start){
        ve.push_back(x);
        x=path[x];
    }
    cout<<start;
    for(int i=ve.size()-1;i>=0;i--){
        cout<<"-->"<<ve[i];
    }
    cout<<":"<<dij[stop];
    return 0;
}