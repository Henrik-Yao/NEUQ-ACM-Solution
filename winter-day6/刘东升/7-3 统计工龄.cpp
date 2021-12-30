#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 110;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int n, a[55];

int main()
{
    in(n);
    for(int i = 1; i <= n; ++i)
    {
        int x; in(x);
        a[x]++;
    }
    for(int i = 0; i <= 50; ++i)
        if(a[i])
        {
            cout << i << ":" << a[i] << "\n";
        }
    return 0;
}
