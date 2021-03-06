#include <bits/stdc++.h>
using namespace std;
//拓扑排序
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> edge[110]; //记录所有边关系
        queue<int> q;
        vector<int> aov; //拓扑序列
        int in[110];     //计算入度
        memset(in, 0, sizeof(in));
        for (int i = 0; i < m; i++)
        {
            int d, u;
            cin >> d >> u;        // d应该在u后
            in[u]++;              //在后面的u入度应++
            edge[d].push_back(u); //将u推入d的next序列中
        }
        //开始构建拓扑序列
        int count = 0;
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
            {
                q.push(i); //将入度为0的一号元素入列
                count++;
            }
        }
        if (count > 1)
            flag = 0;
        while (!q.empty())
        {
            int c = 0;
            int p = q.front();
            q.pop();          //让入度为0的元素出队
            aov.push_back(p); //让出队的进入拓扑序列
            for (int i = 0; i < edge[p].size(); i++)
            {
                in[edge[p][i]]--; // p后面的元素入度--
                if (in[edge[p][i]] == 0)
                {
                    q.push(edge[p][i]);
                    c++;
                }
            }
            if (c > 1)
                flag = 0;
        }
        if (aov.size() == n && flag == 1)
            cout << 1 << endl;
        else if (aov.size() < n)
            cout << 0 << endl;
        else if (aov.size() == n && flag == 0)
            cout << 2 << endl;
    }

    return 0;
}