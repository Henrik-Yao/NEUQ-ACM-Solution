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

int lena, lenb, lenc;
int a[MAXN], b[MAXN], c[MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x;
    while(cin >> x)
    {
        if(x & 1) a[++lena] = x;
        else b[++lenb] = x;
        c[++lenc] = x;
    }
    sort(a + 1, a + 1 + lena);
    sort(b + 1, b + 1 + lenb);
    sort(c + 1, c + 1 + lenc);
    if(lenc)
    {
        for(int i = 1; i < lenc; ++i)
            cout << c[i] << "->";
        cout << c[lenc];
    }
    cout << "\n";
    if(lena)
    {
        for(int i = 1; i < lena; ++i)
            cout << a[i] << "->";
        cout << a[lena];
    }
    cout << "\n";
    if(lenb)
    {
        for(int i = 1; i < lenb; ++i)
            cout << b[i] << "->";
        cout << b[lenb];
    }
    return 0;
}