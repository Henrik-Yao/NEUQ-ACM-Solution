#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 100010;

int n, a[MAXN];
int b[MAXN], c[MAXN], tmp[MAXN];

void merge(int cntl, int cntr)
{
    int l = 1, r = 1;
    for(int i = 1; i <= cntl + cntr; ++i)
    {
        if(l > cntl) tmp[i] = c[r++];
        else if(r > cntr) tmp[i] = b[l++];
        else
        {
            if(b[l] <= c[r]) tmp[i] = b[l++];
            else tmp[i] = c[r++];
        }
    }
}

void solve(int l, int r)
{
    if(l == r) return;
    int mid = (l + r) >> 1;
    solve(l, mid); solve(mid + 1, r);
    int cntl = 0, cntr = 0;
    for(int i = l; i <= mid; ++i) b[++cntl] = a[i];
    for(int i = mid + 1; i <= r; ++i) c[++cntr] = a[i];
    merge(cntl, cntr);
    for(int i = l; i <= r; ++i) a[i] = tmp[i - l + 1];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    solve(1, n);
    for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
    return 0;
}