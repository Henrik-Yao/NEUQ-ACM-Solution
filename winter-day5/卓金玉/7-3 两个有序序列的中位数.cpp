#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    list<int> l;
    int num;
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> num;
        l.push_back(num);
    }
    l.sort();
    auto it = l.begin();
    int i = 0;
    while (i != ceil((2 * n + 1) / 2) - 1)
    {
        it++;
        i++;
    }
    cout << *it << endl;
    return 0;
}