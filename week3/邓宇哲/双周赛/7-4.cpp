#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
main()
{
    double a[100];
    memset(a, 9999999, sizeof(a));
    int n;
    while (cin >> n)
    {
        a[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int p = 0; p < i; p++)
                a[i] = min(a[i], a[p] * 2 + pow(2,i-p)-1);
        }
        cout << a[n - 1] << endl;
    }
}
