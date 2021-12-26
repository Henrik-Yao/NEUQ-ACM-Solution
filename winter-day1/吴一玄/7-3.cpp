#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 1000010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int n, m, k, a[1010];

int back(int pos, int num)
{
    if(num == 1 && a[pos]) return pos;
    int nxt = pos - 1;
    if(!nxt) nxt = n;
    if(!a[pos]) pos = back(nxt, num);
    else pos = back(nxt, num - 1);
    return pos;
}

int nxts(int pos, int num)
{
    if(num == 1 && a[pos]) return pos;
    int nxt = pos + 1;
    if(nxt > n) nxt = 1;
    if(!a[pos]) pos = nxts(nxt, num);
    else pos = nxts(nxt, num - 1);
    return pos;
}

int main()
{
    in(n, m, k);
    for(int i = 0; i <= n; ++i) a[i] = i;
    int now = 1, op = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!op) now = back(now, m);
        else now = nxts(now, k);
        cout << a[now];
        int del = now;
        if(!op) now = back(now, 2);
        else now = nxts(now, 2);
        op ^= 1;
        a[del] = 0;
        cout << " ";
    }
    return 0;
}