#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 1000010;

int n, q;
ll sum[MAXN];

void add(int pos, ll val)
{
    for(; pos <= n; pos += lowbit(pos))
        sum[pos] += val;
}

ll ask(int pos)
{
    ll val = 0;
    for(; pos; pos -= lowbit(pos))
        val += sum[pos];
    return val;
}

int main()
{
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i)
    {
        ll x; scanf("%lld", &x);
        add(i, x);
    }
    while(q--)
    {
        int op; scanf("%d", &op);
        if(op == 1)
        {
            int pos; ll val;
            scanf("%d %lld", &pos, &val);
            add(pos, val);
        }
        else
        {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", ask(r) - ask(l - 1));
        }
    }
    return 0;
}