#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[45];

int main()
{
    f[1] = f[2] = 1;
    for(int i = 3; i <= 40; ++i)
        f[i] = f[i - 1] + f[i - 2];
    int T; scanf("%d", &T);
    f[1]=0;
    while(T--)
    {
        int n; scanf("%d", &n);
        printf("%lld\n", f[n]);
    }
    return 0;
}