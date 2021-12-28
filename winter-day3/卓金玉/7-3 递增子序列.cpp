#include <bits/stdc++.h>
using namespace std;
int n;
set<list<int>> s;
list<int> l;
int a[20];
void dfs(int x)
{
    if (x == n)
    {
        if (l.size() >= 2)
        {
            s.insert(l);
            /*          测试用代码↓
                        for (auto it = l.begin(); it != l.end(); ++it)
                        {
                            cout << *it << " ";
                        }
                        cout << endl;
            */
        }
        return;
    }
    if (!l.size() || a[x] >= l.back())
    {

        l.push_back(a[x]);
        dfs(x + 1);
        l.pop_back();
    }
    if (!l.size() || a[x] != l.back())
    {
        dfs(x + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    /*测试用*/
    //    cout << "= = = = = = =" << endl;
    dfs(0);
    //    cout << "= = = = = = =" << endl;
    cout << s.size() << endl;
    return 0;
}
