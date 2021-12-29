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
                if (i != j) dns[i] = dns[i] + (ll)mp[i][j];
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
