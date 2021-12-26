#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    bool flag = 0;
    for (int i = 0, j = s.length() - 1; i < s.length() / 2; ++i, --j)
    {
        if (s[i] != s[j])
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}