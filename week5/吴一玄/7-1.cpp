#include<bits/stdc++.h>
using namespace std;

int n, q, flag;
map<string, string> fa, ma, sex;
set<string> S;

void up(string x, int dis)
{
    if(x == "" || x == "-1" || dis > 5) return;
    if(S.count(x)) {flag = 1; return;}
    S.insert(x);
    up(fa[x], dis + 1);
    up(ma[x], dis + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        sex[a] = b;
        sex[c] = "M";
        sex[d] = "F";
        fa[a] = c;
        ma[a] = d;
    }
    cin >> q;
    while(q--)
    {
        string a, b;
        cin >> a >> b;
        if(sex[a] == sex[b]) cout << "Never Mind";
        else
        {
            flag = 0; S.clear();
            up(a, 1); up(b, 1);
            if(flag) cout << "No";
            else cout << "Yes";
        }
        if(q) cout << "\n";
    }
    return 0;
}