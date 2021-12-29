    #include<iostream>
    #include<cstring>
    #include<queue>
    #include<algorithm>
    using namespace std;

    const int maxn = 200 + 5, infinity = 1e6;
    int net[maxn][maxn];
    int v[maxn]/*临时标记是否查询过*/, d[maxn]/*到节点i的路径*/;
    int n;

    void Dijkstra(int k) {
        memset(v, 0, sizeof(v));
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n; i++) 
        {
            d[i] = (i == k ? 0 : infinity);
        }
        for (int i = 0; i < n; i++) 
        {
            int x, m = infinity;
            for (int y = 0; y < n; y++) 
            {
                if (!v[y] && d[y] <= m) 
                {
                    m = d[x = y];
                }
            }
            v[x] = 1;
            for (int y = 0; y < n; y++)
            {
                d[y] = min(d[y], d[x] + net[x][y]);
            }
        }
    }

    int main() 
    {
        int e, x, y, cnt;
        while (cin >> n >> e) 
        {
            memset(net, infinity, sizeof(net));
            for (int i = 0; i < n; i++)
            {
                cin >> x >> cnt;
                for (int j = 0; j < cnt; j++)
                {
                    cin >> y;
                    net[x][y] = 1;
                }
            }
            for (int i = 0; i < e; i++)
            {
                cin >> x >> y;
                Dijkstra(x);
                if (d[y] >= infinity)
                {
                    cout << "connection impossible" << endl;
                }
                else 
                {
                    cout << d[y] << endl;
                }
            }
        }
        return 0;
    }