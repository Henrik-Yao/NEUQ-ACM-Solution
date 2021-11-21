#include <iostream>
using namespace std;
long m[50001];
bool done[50001];
bool dfs(long);
bool out(int);
long s;
long n;
main()
{
    cin >> n;
    for (long i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    cin >> s;
    if (dfs(s))
    {
        cout << "True";
    }
    else
        cout << "False";
}
bool out(int i)
{
    return (i < 0 || i >= n);
}
bool dfs(long s)
{
    if (m[s] == 0)
    {
        return true;
    }
    done[s] = 1;
    if (!out(s + m[s]) && !done[s + m[s]])
    {
        if (dfs(s + m[s]))
        {
            return true;
        }
    }
    if (!out(s - m[s]) && !done[s - m[s]])
    {
        if (dfs(s - m[s]))
        {
            return true;
        }
    }
    return false;
}