#include<bits/stdc++.h>
using namespace std;
const int N = 10;
char a[N] ,path[N];
bool st[N];
int n;
string s;

void dfs(int u)
{
    if (u == n)
    {
      for (int i = 0; i < n; ++ i) cout << path[i];
      puts("");
      return;
    }

    for (int i = 0; i < n; ++ i)
    {
      if (!st[i])
      {
        st[i] = true;
        path[u] = s[i];
        dfs(u + 1);
        st[i] = false;
      }
    }
}

int main()
{
  cin >> s;
  n = s.size();
  sort(s.begin() , s.end());

  dfs(0);
  return 0;
}

//深度优先搜索