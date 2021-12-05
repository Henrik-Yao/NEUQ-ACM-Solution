#include <bits/stdc++.h>
using namespace std;
string s;
int p = -1;
string getString(int x)
{
    p = max(x, p);
    int i = 0;
    string newString = "";
    if (x == s.length())
    {
        return "";
    }
    if (s[x] == '[')
    {
        newString = getString(x + 1);
        newString += getString(p + 1);
    }
    else if (s[x] == ']')
    {
        return "";
    }
    else if (s[x] >= '0' && s[x] <= '9')
    {
        i = s[x] - '0';
        if ((x + 1) < s.length() && s[x + 1] >= '0' && s[x + 1] <= '9')
        {
            i = i * 10 + (s[++x] - '0');
        }
        string temp = getString(x + 1);
        for (int j = 0; j < i; ++j)
        {
            newString += temp;
        }
    }
    else
    {
        newString = s[x] + getString(x + 1);
    }
    return newString;
}

int main()
{
    getline(cin, s);
    string newString = getString(0);
    cout << newString << endl;
    return 0;
}