#include<bits/stdc++.h>
using namespace std;

int n,m,q,u,v;
bool va[100002],vb[100002];
long long c,d,money,sum[100002];
long long cc[100002];
long long vr[100002];
long long rate[100002];

struct node{
    int name;
    long long dis;
    
    friend bool operator < (const node &a,const node &b){
        return (a.dis>b.dis);
    }
};

vector <pair<int,long long> > cash2[100002],voucher2[100002];
multiset<long long> cost;
priority_queue<node> Q; 

void Dij(int t, vector<pair<int,long long> >a[], long long dis[], bool visit[]){
    dis[t] = 0;
    Q.push(node{t,0});
    
    while(!Q.empty()){
        int now = Q.top().name;
        Q.pop();
        if(visit[now] == 1) 
			continue;
        visit[now] = 1;
        
        for(int i=0; i<a[now].size(); i++){
            v = a[now][i].first;
            money = a[now][i].second;
            if(dis[v] > dis[now]+money){
                dis[v] = dis[now]+money;
                Q.push(node{v,dis[v]});
            }
        }
    }
}

int main(){
    cin >> n >> m >> q;
    
    for(int i=0; i<m; i++){
        cin >> u >> v >> c >> d;
        cash2[u].push_back({v,c});          
        voucher2[v].push_back({u,d});
    }
    
    for(int i=1; i<=n; i++) 
		cin >> rate[i];

    memset(va, 0, sizeof(va));
    memset(vb, 0, sizeof(vb));
    memset(cc, 0x3f, sizeof(cc));
    memset(vr, 0x3f, sizeof(vr));

    Dij(1, cash2, cc, va);
    Dij(n, voucher2, vr, vb);

    memset(sum, 0, sizeof(sum));
    
    for(int i=1; i <= n; i++){
        if(cc[i] == cc[100001] || vr[i] == vr[100001])
            continue;
        sum[i] = cc[i]+(vr[i]+rate[i]-1)/rate[i];
        cost.insert(sum[i]);
    }

    int city,change;
    
    for(int i=0; i<q; i++){
        cin >> city >> change;
        
        if(sum[city] == 0 || rate[city] == change)
            cout << *cost.begin() << endl;
        else{
            cost.erase(cost.find(sum[city]));
            rate[city] = change;
            sum[city] = cc[city]+(vr[city]+rate[city]-1)/rate[city];
            cost.insert(sum[city]);
            cout << *cost.begin() << endl;
        }
    }
    
    
    
    return 0;
}


//用Dijskra最短路算法分别算出:使用现金从城市1出发，到达所有城市的最小花费；使用旅游金从城市i出发，到达城市n的最小花费；通过枚举中转点的方式，得到在第i个城市将现金换成旅游金的情况下所需要的现金总额。最后将所有中转点所要用的花费储存在一个multiset容器cost中。在更新汇率时，将更新前花费从cost中删除，并插入新值，然后输出cost中的最小值即可。


