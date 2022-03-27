#include <iostream>
#include <map>
using namespace std;
map<char, bool> chars;
main()
{
    string origin, target;
    while (getline(cin, origin) && getline(cin, target))
    {
        int ol = origin.length();
        int tl = target.length();
        for (int i = 0; i < tl; i++)
        {
            chars[target[i]] = 1;
        }
        for (int i = 0; i < ol; i++)
        {
            char ch = origin[i];
            if (chars[origin[i]])
                continue;
            cout << origin[i];
        }
        cout << endl;
        chars.clear();
    }
}