#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 110;

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
        for(int i = 1; i <= m; ++i)
        {
            int u, v, z; in(u, v, z);
            ++u, ++v;
            f[u][v] = f[v][u] = z;
        }
        for(int i = 1; i <= n; ++i) f[i][i] = 0;
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        int mx = 0x7fffffff, id = 0;
        for(int i = 1; i <= n; ++i)
        {
            int sum = 0;
            for(int j = 1; j <= n; ++j) sum += f[i][j];
            if(sum < mx)
            {
                mx = sum;
                id = i;
            }
        }
        cout << id - 1 << "\n";
    }
    return 0;
}