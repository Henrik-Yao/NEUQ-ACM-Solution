#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
const int N = 100010 , M=200010*2;
const LL inf=0x3f3f3f3f3f3f3f3fll;
//链式向前星存储图
int h1[N],h2[N],e[M],ne[M],w[M],idx;
int st[N];
int n,m,q;
int radio[N];
LL dist1[N],dist2[N];
//添加有权边
void add(int h[],int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
//堆优化的dijkstra算法
void dijkstra(int h[],LL dist[],int start){
     memset(dist,0x3f,sizeof dist1);
     dist[start]=0;
     memset(st,0,sizeof st);
     priority_queue<PII,vector<PII>,greater<PII> > heap;
     heap.push({0,start});
     while(heap.size()){
         int v=heap.top().second;
         heap.pop();
         if(st[v]) continue;
         st[v]=true;
         for(int i=h[v];~i;i=ne[i]){
             int j=e[i];
             if(dist[j]>dist[v]+w[i]){
                 dist[j]=dist[v]+w[i];
                 heap.push({dist[j],j});
             }
         }
     }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    memset(h1,-1,sizeof h1);
    memset(h2,-1,sizeof h2);
    for(int i=0;i<m;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(h1, a, b, c);
        add(h2, b, a, d);
    }
    for(int i=1;i<=n;i++)
        cin >> radio[i];
    dijkstra(h1, dist1, 1);
    dijkstra(h2, dist2, n);
    multiset<LL> s;
    for(int i = 1;i <= n; i ++ ){
    //必须要可以连通
        if(dist1[i] != inf && dist2[i] != inf){
        //此时对于后面需要的代金券兑换的现金需要向上取整,所以要加radio[i]-1
           s.insert(dist1[i]+(dist2[i]+radio[i]-1)/radio[i]);
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(dist1[a]!=inf && dist2[a] !=inf){
        s.erase(s.find(dist1[a]+(dist2[a]+radio[a]-1)/radio[a]));
        radio[a] = b;
        s.insert(dist1[a]+(dist2[a]+radio[a]-1)/radio[a]);
        }
        cout << *s.begin()<<endl;
    }
    return 0;
}