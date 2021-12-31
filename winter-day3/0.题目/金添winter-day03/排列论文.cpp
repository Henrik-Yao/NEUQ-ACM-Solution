#include <bits/stdc++.h>
using namespace std;
//��������
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> edge[110]; //��¼���б߹�ϵ
        queue<int> q;
        vector<int> aov; //��������
        int in[110];     //�������
        memset(in, 0, sizeof(in));
        for (int i = 0; i < m; i++)
        {
            int d, u;
            cin >> d >> u;        // dӦ����u��
            in[u]++;              //�ں����u���Ӧ++
            edge[d].push_back(u); //��u����d��next������
        }
        //��ʼ������������
        int count = 0;
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0)
            {
                q.push(i); //�����Ϊ0��һ��Ԫ������
                count++;
            }
        }
        if (count > 1)
            flag = 0;
        while (!q.empty())
        {
            int c = 0;
            int p = q.front();
            q.pop();          //�����Ϊ0��Ԫ�س���
            aov.push_back(p); //�ó��ӵĽ�����������
            for (int i = 0; i < edge[p].size(); i++)
            {
                in[edge[p][i]]--; // p�����Ԫ�����--
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