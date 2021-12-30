#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; // n��·����,m��ѯ��
    while (cin >> n >> m)
    {
        int map[100][100];
        memset(map, 0x3f, sizeof(map)); //���������㷨��ʼ��ֵΪ0x3f��0x7f̫�󣬻����
        for (int i = 0; i < n; i++)
        {
            int z, num;
            cin >> z >> num;
            for (int j = 0; j < num; j++)
            {
                int remp;
                cin >> remp;
                map[i][remp] = 1; //ÿ��һ����ΪȨֵΪ1
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (i == j)
                {
                    map[i][j] = 0;
                }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (map[i][j] > map[i][k] + map[k][j])
                    {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int remp1, remp2;
            cin >> remp1 >> remp2;
            if (map[remp1][remp2] >= 100)
                cout << "connection impossible" << endl;
            else
                cout << map[remp1][remp2] << endl;
        }
    }

    return 0;
}