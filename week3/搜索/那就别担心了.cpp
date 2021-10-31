#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> g[501];
int flag = 1;
int way[1000]={0};

int dfs(int s)
{
    if(way[s] != 0)
    {
        return way[s];
    }
    int a;
    a = g[s].size();
    if(a == 0) 
        flag=0;
    for(int i=0; i < a; i++)
    {
        way[s] = way[s]+dfs(g[s][i]);
    }
    return way[s];
}

int main()
{
    int n, m, s, d;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    cin >> s >> d;
    if(g[d].size() != 0) 
        flag = 0;
    way[d] = 1;
    cout << dfs(s);
    if (flag != 0)
        cout << " Yes";
    else
        cout << " No";
    return 0;
}

