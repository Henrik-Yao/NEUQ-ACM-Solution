#include <bits/stdc++.h>
using namespace std;
int n, m, v, w, a, b, cnct, sa[501];
vector<int> e[501];
int dfs(int ii)
{
    if (sa[ii] != 0)
    {
        return sa[ii];
    }
    for (int j : e[ii])
    {
        if (sa[j] == 0)
        {
            dfs(j);
        }
        sa[ii] += sa[j];
    }
    if (sa[ii] == 0)
    {
        cnct = 1;
    }
    return sa[ii];
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &v, &w);
        e[v].push_back(w);
    }
    scanf("%d %d", &a, &b);
    sa[b] = 1;
    dfs(a);
    printf("%d ", sa[a]);
    if (cnct)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    return 0;
}
