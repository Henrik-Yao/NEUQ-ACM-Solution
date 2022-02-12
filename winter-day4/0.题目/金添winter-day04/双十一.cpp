#include <bits/stdc++.h>
using namespace std;
//���·���㷨
// floyed ���������㷨
int ans[100][100];
int main()
{
    int n, e;
    while (cin >> n >> e)
    {
        int city[100] = {0};
        memset(ans, 0x3f, sizeof(ans)); //��ans��������
        for (int i = 0; i < e; i++)
        {
            int remp1, remp2, remp3;
            cin >> remp1 >> remp2 >> remp3;
            ans[remp1][remp2] = remp3;
            ans[remp2][remp1] = remp3;
        }
        // cout << ans[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (i == j)
                    ans[i][j] = 0;
        }
        for (int k = 0; k < n - 1; k++) //�м��
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (ans[i][j] > ans[i][k] + ans[k][j])
                    {
                        ans[i][j] = ans[i][k] + ans[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                city[i] += ans[i][j];
            }
        }
        int min = 1000000;
        for (int i = 0; i < n; i++)
        {
            if (min > city[i])
                min = city[i];
        }
        for (int i = 0; i < n; i++)
            if (min == city[i])
            {
                cout << i << endl;
                break;
            }
    }
    return 0;
}