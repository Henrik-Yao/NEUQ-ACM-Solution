#include <iostream>
#include <algorithm>
using namespace std;
struct cai
{
    int v;
    int t;
};
main()
{   
    int n, T;
    cin >> n >> T;
    int D[n] = {0};
    cai a[n];
    for (int i = 0; i < n;i++)
    {
        cin >> a[i].v >> a[i].t;
        if(a[i].t>T)
        {
            D[i] = a[i].v - (a[i].t - T);
        }
        else
            D[i] = a[i].v;
    }
    sort(D, D + n);
    cout << D[n - 1];
}
