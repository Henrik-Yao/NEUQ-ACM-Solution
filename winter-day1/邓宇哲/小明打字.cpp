#include <deque>
#include <iostream>
using namespace std;
bool func = true;
main()
{
    deque<char> outcome;
    int point1 = 0;
    deque<char>::iterator point;
    string raw;
    getline(cin, raw);
    for (int i = 0; i < raw.length(); i++)
    {
        point = outcome.begin();
        if (raw[i] == '{')
        {
            if (point1 != 0)
            {
                point1--;
            }
        }
        else if (raw[i] == '}')
        {
            if (point1 < outcome.size())
            {
                point1++;
            }
        }
        else if (raw[i] == '[')
        {
            point1 = 0;
        }
        else if (raw[i] == ']')
        {
            if (outcome.size() != 0)
            {
                point1 = outcome.size();
            }
        }
        else if (raw[i] == '-')
        {
            func = !func;
        }
        else if (raw[i] == '=')
        {
            point += point1;
            outcome.erase(--point);
            point1--;
        }
        else
        {
            point += point1;
            if (func == true)
            {
                if (point != outcome.end())
                {
                    outcome.insert(point, raw[i]);
                }
                else
                    outcome.push_back(raw[i]);
            }
            else
            {
                if (point != outcome.end())
                {
                    *point = raw[i];
                }
                else
                    outcome.push_back(raw[i]);
            }
            point1++;
        }
    }
    for (deque<char>::iterator i = outcome.begin(); i != outcome.end(); i++)
    {
        cout << *i;
    }
}
