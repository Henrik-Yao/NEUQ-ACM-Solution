#include<bits/stdc++.h>
using namespace std;

map<int, int> H;
string s;

string solve(int l, int r)
{
    string ans = "";
    for(int i = l; i < r; ++i)
    {
        if(s[i] == '[')
        {
            int x = 0, j = i + 1;
            for(; j < s.size(); ++j)
            {
                if(isdigit(s[j])) x = x * 10 + s[j] - 48;
                else break;
            }
            string k = solve(j, H[i]);
            while(x--) ans += k;
            i = H[i];
        }
        else ans += s[i];
    }
    return ans;
}

int main()
{
    cin >> s;
    stack<int> x;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '[') x.push(i);
        if(s[i] == ']')
        {
            H[x.top()] = i;
            x.pop();
        }
    }
    cout << solve(0, s.size()) << "\n";
    return 0;
}