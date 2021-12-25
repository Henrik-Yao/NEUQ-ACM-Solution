#include <deque>
#include <iostream>
using namespace std;
main()
{
    string a;
    deque<char> z;
    getline(cin, a);
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            z.push_back(a[i]);
        }
        else if (a[i] == ')' && *z.rbegin() == '(')
        {
            z.pop_back();
        }
        else if (a[i] == ']' && *z.rbegin() == '[')
        {
            z.pop_back();
        }
        else if (a[i] == '}' && *z.rbegin() == '{')
        {
            z.pop_back();
        }
    }
    if (z.size() !=0)
    {
        cout << "no";
    }
    else
        cout << "yes";
}
