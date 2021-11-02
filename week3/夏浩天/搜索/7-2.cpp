#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
vector<int> road[501];
int flag = 0;//判断是否中断
int dtgh[501];//记录每个节点经过次数
int dfs(int n, int end)
{
    int flag_pd = 0;
    if (dtgh[n]) return dtgh[n];
    for (auto lsz : road[n])
    {
        flag_pd = 1;
        dtgh[n] += dfs(lsz, end);
    }
    if (flag_pd == 0)
        flag = 1;//中断
    return dtgh[n];
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int q1, q2;
        cin >> q1 >> q2;
        road[q1].push_back(q2);
    }
    int start, end;
    cin >> start >> end;
    dtgh[end] = 1;
    int end1 = dfs(start, end);
    cout << end1 << " ";
    if (flag == 1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}