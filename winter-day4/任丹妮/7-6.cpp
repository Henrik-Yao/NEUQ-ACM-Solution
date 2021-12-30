#include <bits/stdc++.h>
using namespace std;
#define N 100006
#define pil pair<int,long long>
struct node{
    int id;
    long long dis;
    friend int operator <(const node &a,const node &b){
        return a.dis>b.dis;
    }
};
int n,m,q,u,v,xi,vis1[N],vis2[N];
long long c,d,w,ai,huan[N],cahsD[N],voucherD[N],tran[N];
vector<pil>cashE[N],voucherE[N];
multiset<long long>minCost;
priority_queue<node>Q;
void Dijskra(int s,vector<pil>E[],long long Dis[],int Vis[]){
    fill(Dis+1,Dis+n+1,LLONG_MAX);
    Dis[s]=0;
    Q.push(node{s,0});
    while(!Q.empty()){
        int now=Q.top().id;
        Q.pop();
        if(Vis[now]) continue;
        Vis[now]=1;
        for(int i=0;i<(int)E[now].size();i++){
            v=E[now][i].first;
            w=E[now][i].second;
            if(Dis[v]>Dis[now]+w){
                Dis[v]=Dis[now]+w;
                Q.push(node{v,Dis[v]});
            }
        }
    }
}
int main(){
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        cin>>u>>v>>c>>d;
        cashE[u].push_back({v,c});
        voucherE[v].push_back({u,d});
    }
    for(int i=1;i<=n;i++)
        cin>>huan[i];
    Dijskra(1,cashE,cahsD,vis1);
    Dijskra(n,voucherE,voucherD,vis2);
    for(int i=1;i<=n;i++){
        if(cahsD[i]==LLONG_MAX|| voucherD[i] == LLONG_MAX)
            continue;
        minCost.insert(tran[i]=cahsD[i]+(voucherD[i]+huan[i]-1)/huan[i]);
    }
    for(int i=0;i<q;i++){
        cin>>xi>>ai;
        if(!tran[xi]||huan[xi]==ai){
            cout<<*minCost.begin()<<endl;
        }
        else {
            minCost.erase(minCost.find(tran[xi]));
            huan[xi]=ai;
            minCost.insert(tran[xi]=cahsD[xi]+(voucherD[xi]+huan[xi]-1)/huan[xi]);
            cout<<*minCost.begin()<<endl;
        }
    }
    return 0;
}
