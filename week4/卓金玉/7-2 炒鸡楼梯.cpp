#include <bits/stdc++.h>
using namespace std;
long long a[41];
int main()
{
    a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    for (int i = 4; i < 41; ++i)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    int T, n;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}