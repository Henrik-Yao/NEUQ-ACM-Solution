​                                                                           day4

1.双十一：

思路：图的遍历，筛出符合要求的城市即可，只需要注意条件筛选。

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mtr = 107;
typedef long long ll;
int mp[107][107];
int main()
{
    int n, e;
    while (~scanf("%d %d", &n, &e))
    {
        memset(mp, 0x3f, sizeof mp);
        for (int i = 1; i <= e; i++)
        {
            int from, to, v;
            scanf("%d %d %d", &from, &to, &v);
            ++from, ++to;
            if (from == to) mp[from][to] = 0;
            else
            {
                mp[from][to] = v;
                mp[to][from] = v;
            }
        }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (mp[i][j] > mp[i][k] + mp[k][j])
                        mp[i][j] = mp[i][k] + mp[k][j];
    
        ll dns[mtr] = { 0 };
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j) dns[i] =dns[i] + (ll)mp[i][j];
            }
        }
        ll ans = 0x3f3f3f3f;
        int pos = 1;
        for (int i = 1; i <= n; i++)
            if (dns[i] < ans) ans = dns[i], pos = i;
        --pos;
        printf("%d\n", pos);
    }
    return 0;
}

3

思路：本题目要求通过读入无向网的边的信息（省略了各顶点的信息，仅用顶点编号来表示），构造图，并利用[Dijkstra算法，求出指定源点到其它各点的最短路径。

#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

typedef struct {
    int v, w;
} Node;

const int nf = 65535;
int n, e, s, d;
int qr[1001], pre[1001];
vector<Node> v[1001];
bool vis[1001] = { false };

void sf(int s) {
    fill(qr, qr + 1001, nf);
    qr[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, minx = nf;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && qr[j] < minx) {
                u = j;
                minx = qr[j];
            }
        }
        if (u == -1)
            break;
        vis[u] = true;
        for (int j = 0; j < v[u].size(); j++) {
            int x = v[u][j].v;
            if (!vis[x] && qr[u] + v[u][j].w < qr[x]) {
                qr[x] = qr[u] + v[u][j].w;
                pre[x] = u;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e / 2; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(Node{ b, c });
        v[b].push_back(Node{ a, c });
    }
    scanf("%d %d", &s, &d);
    if (s == d) {
        printf("%d-->%d:0", s, s);
        return 0;
    }
   sf(s);
    vector<int> ver;
    int x = d;
    while (x != s) {
        ver.push_back(x);
        x = pre[x];
    }
    printf("%d", s);
    for (int i = ver.size() - 1; i >= 0; i--)
        printf("-->%d", ver[i]);
    printf(":%d",qr[d]);
    return 0;
}

6森森旅游

思路：天梯赛的一道题

用Dijskra最短路算法分别算出:
1.使用现金从城市1出发，到达所有城市的最小花费（储存在cashD内）
2.使用旅游金从城市n出发，到达所有城市的最小花费（储存在voucherD内）
这样我们就能通过枚举中转点的方式，得到在第i个城市将现金换成旅游金的情况下所需要的现金总额～就是使用从城市1到达第i个城市所需要的最小现金数 + 从第i个城市到城市n所需要的最小旅游金数所转换成的现金数量，就可以得到在第i个城市兑换所需要的总现金费用，储存在tran[i]内～
huan[i]中储存第i个城市的汇率，cashE[i]和voucherE[i]中储分别储存使用现金和旅游金到达i可下一个城市的花费。最后将所有中转点所要用的花费储存在一个可以有重复值的multiset容器 minCost 中。最后在更新汇率时，将更新前花费从 minCost 中删除，并插入新值，然后输出 minCost 中的最小值。

#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
typedef pair<__int128, int> PII;

inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128 x){
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int h[N], e[M], ne[M], idx;
int h2[N], e2[M], ne2[M], idx2;
__int128 w1[M], w2[M];
__int128 val[N];
int n, m, q;
__int128 d1[N], d2[N];
bool st[N];

void add(int a, int b, __int128 x)
{
    e[idx] = b, w1[idx] = x, ne[idx] = h[a], h[a] = idx++;
}
void add2(int a, int b, __int128 y)
{
    e2[idx2] = b, w2[idx2] = y, ne2[idx2] = h2[a], h2[a] = idx2++;
}

void dij1()
{
    memset(d1, 0x3f, sizeof(d1));
    d1[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
    
        int ver = t.second;
    
        if(st[ver]) continue;
        st[ver] = true;
    
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (d1[j] > t.first + w1[i])
            {
                d1[j] = t.first + w1[i];
                heap.push({d1[j], j});
            }
        }
    }
}

void dij2()
{
    memset(st, 0, sizeof(st));
    memset(d2, 0x3f, sizeof(d2));
    d2[n] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, n});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
    
        int ver = t.second;
    
        if(st[ver]) continue;
        st[ver] = true;
    
        for (int i = h2[ver]; ~i; i = ne2[i])
        {
            int j = e2[i];
            if (d2[j] > t.first + w2[i])
            {
                d2[j] = t.first + w2[i];
                heap.push({d2[j], j});
            }
        }
    }
}


int main()
{
    memset(h, -1, sizeof(h));
    memset(h2, -1, sizeof(h2));
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m;i++)
    {
        int u, v;
        __int128 a, b;
        scanf("%d%d", &u, &v);
        a = read();
        b = read();
        if (u == v)
            continue;
        add(u, v, a);
        add2(v, u, b);
    }
    for (int i = 1; i <= n;i++)
    {
        val[i] = read();
    }
    dij1();
    dij2();

    set<PII> s;
    
    for (int i = 1; i <= n;i++)
    {
        if (d1[i] >= INF || d2[i] >= INF) continue;
        s.insert({d1[i] + ((d2[i] + val[i] - 1) / val[i]), i});
    }
    /*puts("");
    
    __int128 minv = INF;
    int t;
    for (int i = 1; i <= n;i++)
    {
        if (d1[i] >= INF || d2[i] >= INF) continue;
        if (minv > d1[i] + ((d2[i] + val[i] - 1) / val[i]))
        {
            minv = d1[i] + ((d2[i] + val[i] - 1) / val[i]);
            t = i;
            //print(maxv);
            //puts("");
        }
    }*/
    /*for (int i = 1; i <= n;i++)
    {
        print(d1[i]);
        cout << ' ';
        print(d2[i]);
        puts("");
    }*/
    
    for (int i = 0; i < q; i++)
    {
        int x;
        __int128 y;
        scanf("%d", &x);
        y = read();


        if (d1[x] >= INF || d2[x] >= INF)
        {
            auto x = s.begin();
            print(x->first);
        }
    
        else
        {
            s.erase({d1[x] + ((d2[x] + val[x] - 1) / val[x]), x});
            val[x] = y;
            s.insert({d1[x] + ((d2[x] + val[x] - 1) / val[x]), x});
            auto x = s.begin();
            print(x->first);
        }
    
        puts("");
    }
    return 0;
}

