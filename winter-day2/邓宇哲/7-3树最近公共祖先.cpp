#include <deque>
#include <iostream>
using namespace std;
deque<int> list[1000];
int search(int);
int connect(int);
int y, z;
main()
{
    int n;
    int pozition;
    int t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            list[j].clear();
        }
        cin >> pozition;
        connect(pozition);
        cin >> t >> y >> z;
        cout << search(pozition) << endl;
    }
}
int search(int n)
{
    if (n == y || n == z)
    {
        return n;
    }
    if (!list[n].size())
    {
        return -1;
    }
    int k[3] = {-1, -1, -1}, t = 0;

    for (int i = 0; i < list[n].size(); i++)
    {
        int f = search(list[n][i]);
        if (f != -1)
        {
            k[++t] = f;
        }
    }
    if (t == 2)
    {
        return n;
    }
    else if (t == 1)
    {
        return k[t];
    }
    else
    {
        return -1;
    }
}
int connect(int n)
{
    int p = 1;
    while (p != 0)
    {
        cin >> p;
        if (p != 0)
        {
            list[n].push_back(p);
            connect(p);
        }
    }
    return 0;
}