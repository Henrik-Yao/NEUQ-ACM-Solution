#include <iostream>
using namespace std;
int list[100];
int sum[100];
int connect(int, int);
main()
{
    int num = 0;
    while (cin >> list[num++]);
    sum[0] = list[0];
    connect(0, 1);
    int point = 0;
    for (int i = 0; i < 100; i++)
    {
        if (abs(sum[i]) >= abs(sum[point]))
        {
            point = i;
        }
    }
    cout << point;
}
int connect(int point, int deep)
{
    static int L = point;
    if (list[L] == 0)
    {
        return 0;
    }
    int a = list[L];
    sum[deep] += connect(++L, deep + 1);
    sum[deep] += connect(++L, deep + 1);
    return a;
}