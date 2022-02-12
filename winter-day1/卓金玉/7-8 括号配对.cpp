#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> s;
    char ch;
    while (scanf("%c", &ch) != EOF)
    {
        if (ch == '[' || ch == '(' || ch == '{')
        {
            s.push(ch);
        }
        else if (ch == ']')
        {
            if (s.top() == '[')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        else if (ch == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        else if (ch == '}')
        {
            if (s.top() == '{')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
    }
    if (s.empty())
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}