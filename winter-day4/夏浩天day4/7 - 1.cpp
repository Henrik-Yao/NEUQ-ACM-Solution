#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int ma[101][101];
int main()
{
    int n, e;
    while (cin>>n,cin>>e)
    {
        memset(ma, 0x3f, sizeof ma);
        for (int i = 1; i <= e; i++)
        {
            int q, p, v;
            cin >> q >> p >> v;
            q++, p++;
            if (q == p) ma[q][p] = 0;
            else
            {
                ma[q][p] = v;
                ma[p][q] = v;
            }
        }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (ma[i][j] > ma[i][k] + ma[k][j])
                        ma[i][j] = ma[i][k] + ma[k][j];

        long long dis[101] = { 0 };
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j) 
                    dis[i] = dis[i] + (long long)ma[i][j];

        long long ans = 99999999999;
        int pos = 1;
        for (int i = 1; i <= n; i++)
            if (dis[i] < ans)
            {
                ans = dis[i]; pos = i;
            }
        pos--;
        cout << pos << endl;
    }
    return 0;
}
