#include <bits/stdc++.h>
using namespace std;
void permu(string s, int begin);
int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length() - 1; ++i)
    {
        for (int j = 0; j < s.length() - i - 1; ++j)
        {
            if (s[j] > s[j + 1])
            {
                swap(s[j], s[j + 1]);
            }
        }
    }

    permu(s, 0);
    return 0;
}
void permu(string s, int begin)
{
    if (begin == s.length())
        cout << s << endl;

    else
        for (int i = begin; i < s.length(); ++i)
        {
            swap(s[i], s[begin]);
            permu(s, begin + 1);
        }
}
