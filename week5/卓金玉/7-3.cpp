#include <bits/stdc++.h>
using namespace std;
vector<int> vec[20005];
bool vis[20005];
void dfs(int k)
{

    printf("%d ", k);
    vis[k] = 1;
    for (int i = 0; i < vec[k].size(); ++i)
    {
        if (!vis[vec[k][i]])
        {
            dfs(vec[k][i]);
        }
    }
}

int main()
{
    int v, e, va, vb;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &va, &vb);
        vec[va].push_back(vb);
    }
    for (int i = 0; i < v; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    return 0;
}