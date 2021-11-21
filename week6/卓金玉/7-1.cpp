#include <bits/stdc++.h>
using namespace std;
string s, p;
int Next[1000005];
void getNext()
{
    Next[0] = -1;
    int i = 0, len = -1;
    while (i < p.size())
    {
        if (len == -1 || p[i] == p[len])
        {
            i++, len++;
            Next[i] = len;
        }
        else
        {
            len = Next[len];
        }
    }
}

int kmp()
{
    int i = 0, len = 0;
    int cnt = 0;
    getNext(); //计算模式串的next数组
    while (i < s.size())
    {
        if (len == -1 || p[len] == s[i])
            i++, len++;
        else
            len = Next[len];
        if (len == p.size())
        {
            cnt++;
            len = Next[len];
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); //快速输入输出
    getline(cin, s);
    getline(cin, p);
    int sum = kmp();
    cout << sum << endl;

    return 0;
}