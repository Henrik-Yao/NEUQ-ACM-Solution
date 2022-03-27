#include <algorithm>
#include <iostream>
using namespace std;
int path[20000]={0};
int depth = 0;
void dfs(int);
struct node
{
    int connect[500] = {0};
    bool done = 0;
    int num = 0;
};
node nodes[20000];
main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int k;
        cin >> k;
        cin >> nodes[k].connect[nodes[k].num];
        nodes[k].num++;
    }
    for (int i = 0; i < n; i++)
    {
        if(nodes[i].done==0)
        {
            dfs(i);
        }
    }
    for (int i = 0; i < depth;i++)
    {
        cout << path[i] << ' ';
    }
}
void dfs(int s)
{
    if (nodes[s].done)
    {
        return;
    }
    path[depth++] = s;
    nodes[s].done = 1;
    sort(nodes[s].connect, nodes[s].connect + nodes[s].num);
    for (int i = 0; i < nodes[s].num; i++)
    {
        dfs(nodes[s].connect[i]);
    }
}