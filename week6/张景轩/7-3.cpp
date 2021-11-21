#include<iostream>
#include<string.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1000001;
const ull Base = 1000;

int n; ull h[MAX], Pow[MAX];
char s[MAX], t[MAX];
string S;

int main()
{
    getline(cin, S);
    int flag = 1;
    for(int i = 0; i < S.size(); ++i)
    {
        if(S[i] >= 'A' && S[i] <= 'Z') S[i] = S[i] - 'A' + 'a';
        if(S[i] >= 'a' && S[i] <= 'z') s[++n] = S[i], flag = 0;
        else
        {
            if(!flag)
            {
                s[++n] = ' ';
            }
            flag = 1;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        h[i] = h[i - 1] * Base + (ull)s[i];
    }
    Pow[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        Pow[i] = Pow[i - 1] * Base;
    }
    cin >> t + 1;
    int m = strlen(t + 1);
    for(int i = 1; i <= m; ++i)
    {
        if(t[i] >= 'A' && t[i] <= 'Z')
        {
            t[i] = t[i] - 'A' + 'a';
        }
    }
    ull ht = 0;
    int ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        ht = ht * Base + (ull)t[i];
    }
    flag = 0;
    for(int i = 1; i + m - 1 <= n; ++i)
    {
        if(s[i] == ' ')
        {
            flag = 0;
            continue;
        }
        ll hs = h[i + m - 1] - h[i - 1] * Pow[m];
        if(hs == ht)
        {
            if(!flag)
            {
                ++ans;
            }
            flag = 1;
        }
    }
    cout<<ans;
    return 0;
}