#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[51];
signed main()
{
    int n;
    a[1] = 1;
    for (int i = 2; i <= 50; i++)
    {
        if (i < 4)a[i] = a[i - 1] * 2;
        else if(i>=4)a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    while (cin >> n)
    {
        cout << a[n]<<endl;
    }
    return 0;
}