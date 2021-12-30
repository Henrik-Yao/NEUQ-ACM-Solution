#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 310;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int n, m;
int f[MAXN][MAXN];

int main()
{
    while(cin >> n >> m)
    {
        memset(f, 0x3f, sizeof(f));
        for(int i = 1; i <= n; ++i) f[i][i] = 0;
        for(int i = 1; i <= n; ++i)
        {
            int u, k, v; in(u, k);
            ++u;
            while(k--)
            {
                in(v); ++v;
                f[u][v] = 1;
            }
        }
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        while(m--)
        {
            int u, v; in(u, v); ++u, ++v;
            if(f[u][v] == 0x3f3f3f3f) puts("connection impossible");
            else cout << f[u][v] << "\n";
        }
    }
    return 0;
}