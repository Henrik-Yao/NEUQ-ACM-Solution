#include<bits/stdc++.h>
using namespace std;

inline char Getchar()
{
    static char buf[1000010], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

void in() {}
template<typename T, typename... otr_T>
void in(T &x, otr_T &...Ar)
{
    x = 0; int f = 1; char s = Getchar();
    for(; !isdigit(s); s = Getchar()) if(s == '-') f = 0;
    for(; isdigit(s); s = Getchar()) x = (x << 3) + (x << 1) + s - 48;
    x = (f ? x : -x);
    in(Ar...);
}

struct Node
{
    int l, r;
    bool operator < (const Node &x) const
    {
        if(x.r == r) return l > x.l;
        return r < x.r;
    }
};

int T, n;
Node a[1000010];

int main()
{
    in(T);
    while(T--)
    {
        in(n);
        for(int i = 1; i <= n; ++i) in(a[i].l, a[i].r);
        sort(a + 1, a + 1 + n);
        int ans = 0, now = 0;
        for(int i = 1; i <= n; ++i)
            if(a[i].l >= now)
            {
                now = a[i].r;
                ++ans;
            }
        printf("%d\n", n - ans);
    }
    return 0;
}