#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

inline char Getchar()
{
    static char buf[1000010], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline void Read(int &x)
{
    x = 0; int f = 1; char s = Getchar();
    for(; !isdigit(s); s = Getchar()) if(s == '-') f = -1;
    for(; isdigit(s); s = Getchar()) x = x * 10 + s - 48;
    x *= f;
}

const int MAXN = 1000010;

long long ans;
int n, a[MAXN], b[MAXN];

void Mergesort(int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) >> 1;
    Mergesort(l, mid);
    Mergesort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) b[k++] = a[i++];
        else ans += mid - i + 1, b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int i = l; i <= r; ++i) a[i] = b[i];
}

int main()
{
    Read(n);
    for(int i = 1; i <= n; ++i) Read(a[i]);
    Mergesort(1, n);
    printf("%lld\n", ans);
    return 0;
}