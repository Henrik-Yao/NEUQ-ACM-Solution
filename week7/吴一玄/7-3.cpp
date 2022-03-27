#include<bits/stdc++.h>
using namespace std;

map<char, int> H;

int main()
{
    string s;
    while(getline(cin, s))
    {
        string o; getline(cin, o);
        H.clear();
        for(int i = 0; i < o.size(); ++i)
        {
            H[o[i]] = 1;
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(H[s[i]]) continue;
            cout << s[i];
        }
        cout << "\n";
    }
    return 0;
}