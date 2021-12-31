#include <bits/stdc++.h>
using namespace std;
#define N 50005
int a[N];
int n;
bool dfs(int k)
{
    if (k < 0 || k >= n || a[k] == -1)
    {
        return 0;
    }
    int t = a[k];
    a[k] = -1;
    return t == 0 || dfs(k + t) || dfs(k - t);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int beginnum;
    scanf("%d", &beginnum);
    if (dfs(beginnum))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}