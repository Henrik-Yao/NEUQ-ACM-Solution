#include <iostream>
using namespace std;
struct city
{
    bool done = 0;
    bool safe = 0;
    int conect[101] = {0};
    int conectnum = 0;
};
bool dfs(city a[], int start, int end);
main()
{
    int m, n, k;
    cin >> m >> n >> k;
    city a[m];
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        a[no].safe = 1;
    }
    for (int i = 0; i < k; i++)
    {
        int d, b;
        cin >> d >> b;
        a[d].conect[a[d].conectnum] = b;
        a[d].conectnum++;
        a[b].conect[a[b].conectnum] = d;
        a[b].conectnum++;
    }
    int there, that;
    cin >> there >> that;
    if (!(a[that].safe))
    {
        cout << "The city " << that << " is not safe!";
        return 0;
    }
    if (dfs(a, there, that))
    {
        cout << "The city " << that << " can arrive safely!";
    }
    else
        cout << "The city " << that << " can not arrive safely!";
}
bool dfs(city a[], int start, int end)
{
    if (start == end)
    {
        return true;
    }
    if (a[start].done)
    {
        return false;
    }
    a[start].done = 1;
    for (int i = 0; i < a[start].conectnum; i++)
    {
        if (dfs(a, a[start].conect[i], end))
        {
            return true;
        }
    }
    return false;
}