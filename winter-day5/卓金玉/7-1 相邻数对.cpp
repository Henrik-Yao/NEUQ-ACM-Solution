#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    int num, cnt = 0;
    while (n--)
    {
        cin >> num;
        s.insert(num);
    }
    auto it = s.begin();
    auto itt = ++s.begin();
    int a, b;
    for (it, itt; itt != s.end(); ++itt, ++it)
    {
        a = *it;
        b = *itt;
        // cout << "a = " << a << " "
        //      << "b = " << b << endl;
        if (b - a == 1)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}