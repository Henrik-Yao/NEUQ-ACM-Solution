#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<char> l;
    list<char>::iterator it = l.begin();
    string s;
    getline(cin, s);
    int flag = 1;
    for (int i = 0; i < s.length(); ++i)
    {

        if ((isalpha(s[i]) || isspace(s[i])) && flag == 1)
        {
            l.insert(it, s[i]);
        }
        else if ((isalpha(s[i]) || isspace(s[i])) && flag == -1)
        {
            l.erase(it++);
            l.insert(it, s[i]);
        }
        else
        {
            switch (s[i])
            {
            case '[':
                it = l.begin();
                break;
            case ']':

                it = l.end();
                break;
            case '{':
                if (it != l.begin())
                    it--;
                break;
            case '}':
                if (it != l.end())
                    it++;
                break;
            case '=':
                it--;
                l.erase(it++);
                break;
            case '-':
                flag *= -1;
                break;
            }
        }
    }
    // cout << "*it = " << *it << "|" << endl;
    for (auto iter = l.begin(); iter != l.end(); ++iter)
    {
        cout << *iter;
    }
    return 0;
}