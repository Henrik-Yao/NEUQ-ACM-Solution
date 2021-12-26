#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    while (getline(cin, s))
    {
        int zuo = 0, you = 0;
        stack<char> stk;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                stk.push(s[i]);
            }
            else if ((stk.empty() || stk.top() != '(') && s[i] == ')')
            {
                zuo++;
            }
            else if (stk.top() == '(' && s[i] == ')')
            {
                stk.pop();
            }
        }
        if (stk.empty() && zuo == 0)
        {
            printf("Match\n");
        }
        else
        {
            you = stk.size();
            printf("%d\n", zuo + you);
            for (int i = 0; i < zuo; ++i)
            {
                printf("(");
            }
            cout << s;
            for (int i = 0; i < you; ++i)
            {
                printf(")");
            }
            printf("\n");
        }
    }

    return 0;
}