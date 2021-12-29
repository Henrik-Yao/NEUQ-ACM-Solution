#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
typedef pair<__int128, int> PII;

inline __int128 read() {
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

inline void print(__int128 x) {
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
    heap.push({ 0, 1 });

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (d1[j] > t.first + w1[i])
            {
                d1[j] = t.first + w1[i];
                heap.push({ d1[j], j });
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
    heap.push({ 0, n });

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h2[ver]; ~i; i = ne2[i])
        {
            int j = e2[i];
            if (d2[j] > t.first + w2[i])
            {
                d2[j] = t.first + w2[i];
                heap.push({ d2[j], j });
            }
        }
    }
}


int main()
{
    memset(h, -1, sizeof(h));
    memset(h2, -1, sizeof(h2));
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++)
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
    for (int i = 1; i <= n; i++)
    {
        val[i] = read();
    }
    dij1();
    dij2();

    set<PII> s;

    for (int i = 1; i <= n; i++)
    {
        if (d1[i] >= INF || d2[i] >= INF) continue;
        s.insert({ d1[i] + ((d2[i] + val[i] - 1) / val[i]), i });
    }
   
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
            s.erase({ d1[x] + ((d2[x] + val[x] - 1) / val[x]), x });
            val[x] = y;
            s.insert({ d1[x] + ((d2[x] + val[x] - 1) / val[x]), x });
            auto x = s.begin();
            print(x->first);
        }

        puts("");
    }
    return 0;
}
