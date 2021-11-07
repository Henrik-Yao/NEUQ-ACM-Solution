#include <cstring>
#include <iostream>
using namespace std;
long long sum = 0;
bool exist = 1;
struct mingti
{
    long long point[505];
    long long num = 0;
    bool done = 0;
    int ways = 0;
};
mingti a[505];
void dfs(long long, long long);
main()
{
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        long long t, r;
        cin >> t >> r;
        a[t].point[a[t].num] = r;
        a[t].num++;
    }
    long long j, k;
    cin >> j >> k;
    dfs(j, k);
    cout << a[j].ways << ' ';
    if (exist)
    {
        cout << "Yes";
    }
    else
        cout << "No";
}
void dfs(long long n, long long d)
{
    if (n == d)
    {
        a[n].ways++;
        return;
    }
    if (a[n].num == 0)
    {
        exist = 0;
    }
    for (long long i = 0; i < a[n].num; i++)
    {
        if (!(a[n].done))
        {
            a[n].done = 1;
            if (a[a[n].point[i]].ways == 0)
            {
                dfs(a[n].point[i], d);
            }

            a[n].ways += a[a[n].point[i]].ways;
            a[n].done = 0;
        }
    }
}