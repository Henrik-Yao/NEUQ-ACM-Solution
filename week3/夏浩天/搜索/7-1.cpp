#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
vector<int> road[101];
int safe[101], visited[101];
void dfs(int x)
{
    visited[x] = 1;//将所有路过标记为一
    for (auto bh:road[x])
    {
        if (visited[bh]==0 && safe[bh]==1)
            dfs(bh);
    }
}

int main()
{
    memset(safe, 0, sizeof(safe));
    memset(visited, 0, sizeof(visited));
    int n, m, k;
    cin >> m >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        safe[x] = 1;
    }
    for(int i=0;i < k;i++)
    {
        int q1, q2;
        cin >> q1 >> q2;
        road[q1].push_back(q2);
        road[q2].push_back(q1);
    }
    int s, t;
    cin >> s >> t;
    if (safe[t]==0)
        printf("The city %d is not safe!", t);
    else 
    {
        dfs(s);
        if (visited[t]==1) 
            printf("The city %d can arrive safely!", t);
        else 
            printf("The city %d can not arrive safely!", t);
    }
}