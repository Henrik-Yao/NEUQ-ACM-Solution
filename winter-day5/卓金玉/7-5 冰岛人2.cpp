#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
#define MAX 100005
int N, M;
int sex[MAX];
string f[MAX], s[MAX];
bool vis[MAX];
int father[MAX];
string get(string str, int p)
{
    int pos;
    if (p == 1)
        pos = str.rfind("sson");
    else
        pos = str.rfind("sdottir");
    return str.substr(0, pos);
}
void init()
{
    for (int i = 1; i <= N; ++i)
        father[i] = -1;
}
bool judge(int l, int r)
{
    memset(vis, false, sizeof(vis));
    set<int> stl, str;
    int Count = 1;
    int k = l;
    while (k != -1)
    {
        vis[k] = true;
        if (Count < 5)
            stl.insert(k);
        if (k == r)
            return false;
        k = father[k];
        Count++;
    }
    k = r;
    Count = 1;
    while (k != -1)
    {
        if (Count < 5)
            str.insert(k);
        if (vis[k])
        {
            if (stl.count(k) || str.count(k))
                return false;
        }
        k = father[k];
        Count++;
    }
    return true;
}
int main(void)
{
    cin >> N;
    init();
    for (int i = 1; i <= N; ++i)
    {
        cin >> f[i] >> s[i];
        mp[f[i]] = i;
        int len = s[i].length();
        if (s[i][len - 1] == 'n')
            sex[i] = 1;
        else if (s[i][len - 1] == 'r')
            sex[i] = 0;
        else if (s[i][len - 1] == 'm')
            sex[i] = 1;
        else
            sex[i] = 0;
    }
    for (int i = 1; i <= N; ++i)
    {
        int len = s[i].length();
        if (s[i][len - 1] == 'n')
        {
            string fs = get(s[i], 1);
            int fp = mp[fs];
            father[i] = fp;
        }
        else if (s[i][len - 1] == 'r')
        {
            string fs = get(s[i], 0);
            int fp = mp[fs];
            father[i] = fp;
        }
    }
    cin >> M;
    string lf, ls, rf, rs;
    for (int i = 1; i <= M; ++i)
    {
        cin >> lf >> ls >> rf >> rs;
        if (!mp.count(lf) || !mp.count(rf))
            cout << "NA" << endl;
        else
        {
            int lp = mp[lf], rp = mp[rf];
            if (sex[lp] == sex[rp])
                cout << "Whatever" << endl;
            else
            {
                if (judge(lp, rp))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
    }
    return 0;
}
