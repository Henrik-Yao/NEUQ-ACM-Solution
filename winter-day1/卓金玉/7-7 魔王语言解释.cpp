#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> mo;
    char rep;
    list<char> l;
    // string s;
    // getline(cin,s);
    char ch, tmp;
    while (scanf("%c", &ch) != EOF)
    {
        if (isalpha(ch) && mo.empty())
        {
            l.push_back(ch);
        }
        else if (ch == '(')
        {
            mo.push(ch);
            scanf("%c", &rep);
        }
        else if (isalpha(ch) && !mo.empty())
        {
            mo.push(ch);
        }
        else if (ch == ')')
        {
            while (mo.top() != '(')
            {
                l.push_back(rep);
                tmp = mo.top();
                l.push_back(tmp);
                mo.pop();
            }
            mo.pop();
            l.push_back(rep);
        }
    }
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        if (*it == 'A')
        {
            printf("sae");
        }
        else if (*it == 'B')
        {
            printf("tsaedsae");
        }
        else
        {
            cout << *it;
        }
    }
    return 0;
}