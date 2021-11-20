#include<bits/stdc++.h>
using namespace std;

int n, flag;
int v[50010], a[50010];

void dfs(int x)
{
    v[x] = 1;
    if(!a[x]) {flag = 1; return;}
    if(x - a[x] >= 1 && !v[x - a[x]]) dfs(x - a[x]);
    if(x + a[x] <= n && !v[x + a[x]]) dfs(x + a[x]);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int st; scanf("%d", &st); ++st;
    dfs(st);
    if(flag) puts("True");
    else puts("False");
    return 0;
}