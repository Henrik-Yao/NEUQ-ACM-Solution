#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#define lowbit(x) x&(-x)
#define debug(a) cout<<"debug:"<<#a<<"\n"
using namespace std;
typedef long long LL;
typedef pair<LL,LL>P;///first距离，second编号
const LL mod=1e9+7;
const LL maxn=1e5+1000;
struct Edge{
    LL to,val;
};
vector<Edge>g1[maxn];
vector<Edge>g4[maxn];
multiset<LL>s1;
LL dis1c[maxn],disnd[maxn];
LL a[maxn];
LL n,m,q;
bool vis[maxn];
void dijkstra(LL st, vector<Edge>g[], LL dis[]){
     memset(vis,0,sizeof(vis));
     for(LL i=0;i<n+10;i++) dis[i]=1e18;
     priority_queue< P,vector<P>, greater<P> >que;
     dis[st]=0;
     que.push({dis[st],st});
     while(!que.empty()){
        P now=que.top();que.pop();
        LL u=now.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(LL i=0;i<g[u].size();i++){
            LL v=g[u][i].to;
            LL cost=g[u][i].val;
            if(dis[v]>dis[u]+cost){
                dis[v]=dis[u]+cost;
                que.push({dis[v],v});
            }
        }
     }
}
int main(void){
   cin.tie(0);std::ios::sync_with_stdio(false);
   cin>>n>>m>>q;
   for(LL i=1;i<=m;i++){
       LL u,v,c,d;cin>>u>>v>>c>>d;
       g1[u].push_back({v,c});
       g4[v].push_back({u,d});
   }
   for(LL i=1;i<=n;i++) cin>>a[i];
 
   dijkstra(1,g1,dis1c);
   dijkstra(n,g4,disnd);
 
   for(LL i=1;i<=n;i++){///枚举每个点作为中转
       if(dis1c[i]==1e18||disnd[i]==1e18){
            continue;///不更新		
       }
       LL need=dis1c[i]+(disnd[i]+a[i]-1)/a[i];
       s1.insert(need);
   }
//优化：提前把答案都扔到multiset里,然后logn更新最值
   while(q--){
      LL id,num;cin>>id>>num;
      if(dis1c[id]==1e18||disnd[id]==1e18){
            cout<<(*s1.begin())<<"\n";
            continue;///不更新		
      }
      LL temp=dis1c[id]+(disnd[id]+a[id]-1)/a[id];
      s1.erase(s1.find(temp));
 
      a[id]=num;
 
      temp=dis1c[id]+(disnd[id]+a[id]-1)/a[id];
      s1.insert(temp);
      cout<<(*s1.begin())<<"\n";
//      LL mx=2e18;
//      for(LL i=1;i<=n;i++){
//         //由于不知道本次更新的点是否是原来提供最优解的点,暴力更新24分.
//         LL need=dis1c[i]+(disnd[i]+a[i]-1)/a[i];
//         mx=min(mx,need);
//      }
//      cout<<mx<<"\n";
 
   }
   return 0;
}