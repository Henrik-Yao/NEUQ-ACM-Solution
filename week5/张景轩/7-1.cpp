#include<iostream>
#include"map"
#include<set>

using namespace std;

int n, q, flag;
map<string, string> dad, mom, sex;
set<string> S;

void find(string x, int dis)
{
    if(x == "" || x == "-1" || dis > 5) return;
    if(S.count(x)) {flag = 1; return;}
    S.insert(x);
    find(dad[x], dis + 1);
    find(mom[x], dis + 1);
}

int main()
{
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        sex[a] = b;
        sex[c] = "M";
        sex[d] = "F";
        dad[a] = c;
        mom[a] = d;
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
            find(a, 1); find(b, 1);
            if(flag) cout << "No";
            else cout << "Yes";
        }
        if(q) cout << "\n";
    }
    return 0;
}