#include <iostream>
#include <set>
using namespace std;
int list[10001];
int search(int);
int main()
{
    int n, m, q;
    int x, y;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        list[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (x == y)
        {
            continue;
        }
        x = search(x);
        y = search(y);
        list[y] = x;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        if (search(x) == search(y))
        {
            cout << "In the same gang.";
        }
        else
        {
            cout << "In different gangs.";
        }
        cout << endl;
    }
    set<int> sets;
    for (int i = 1; i <= n; i++)
    {
        sets.insert(search(i));
    }
    cout << sets.size() << endl;
}
int search(int x)
{
    if (list[x] == x)
    {
        return x;
    }
    else
        return list[x] = search(list[x]);
}