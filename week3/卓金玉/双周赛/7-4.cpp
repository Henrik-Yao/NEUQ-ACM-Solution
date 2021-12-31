#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i = 1, flag = 2, cnt = 1;
        int re = 1;
        while (cnt++ < n)
        {
            if (i++ <= flag)
                re += pow(2, flag - 1);

            else
            {
                flag++;
                i = 1;
                cnt--;
            }
        }
        printf("%d\n", re);
    }
    return 0;
}
