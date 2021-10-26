#include <cstring>
#include <iostream>
using namespace std;
struct road
{
    int a;
    int b;
};
main()
{
    int n, m;
    cin >> n >> m;
    road ro[m];

    for (int i = 0; i < m; i++)
    {
        cin >> ro[i].a >> ro[i].b;
    }
    int k;
    cin >> k;
    for (int p = 0; p < k; p++)
    {
        int sign[n + 1] = {0};
        int num;
        cin >> num;
        road copys[m];
        memcpy(copys, ro, sizeof(ro));
        for (int o = 0; o < num; o++)
        {
            int city;
            cin >> city;
            sign[city] = 1;
        }
        int boolsss = 1;
        for (int i = 0; i < m; i++)
        {
            if (sign[ro[i].a] == 0 && sign[ro[i].b] == 0)
            {
                boolsss = 0;
            }
        }
        if (!boolsss)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
}
