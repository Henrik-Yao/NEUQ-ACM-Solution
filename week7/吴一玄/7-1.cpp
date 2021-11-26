#include<bits/stdc++.h>
using namespace std;

int n, m;
map<string, string> H;

int main()
{
    string a, b;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        string a, b;
        cin >> a >> b;
        H[b] = a;
    }
    while(m--)
    {
        string s;
        cin >> s;
        if(!H.count(s)) puts("eh");
        else cout << H[s] << "\n";
    }
    return 0;
}