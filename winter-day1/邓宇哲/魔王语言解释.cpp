#include <deque>
#include <iostream>
using namespace std;
deque<char> list;
deque<char>::iterator it = list.begin();
void function(deque<char>&, int &);
main()
{
    string raw;
    getline(cin, raw);
    for (int i = 0; i < raw.length(); i++)
    {
        list.push_back(raw[i]);
    }

    for (int point = 0; point < list.size(); point++)
    {
        it = list.begin() + point;
        if (*it == 'B')
        {
            *it = ' t';
            list.insert(it + 1, 'A');
            it = list.begin() + point;
            list.insert(it + 2, 'd');
            it = list.begin() + point;
            list.insert(it + 3, 'A');
            it = list.begin() + point;
        }
        else if (*it == 'A')
        {
            *it = 's';
            list.insert(it + 1, 'a');
            it = list.begin() + point;
            list.insert(it + 2, 'e');
            it = list.begin() + point;
        }
        else if (*it == '(')
        {
            function(list, point);
        }
    }
    for (int i = 0; i < list.size()-1;i++)
    {
        cout << list[i];
    }
    cout<<endl;
}
void function(deque<char> &a, int &point)
{
    int endin;
    for (endin = point + 1; endin < a.size(); endin++)
    {
        if (a[endin] == ')')
        {
            break;
        }
    }
    int len = endin - point - 1;
    char cache[len];
    for (int i = 0; i < len; i++)
    {
        cache[i] = a[point + i + 1];
    }
    a[point] = a[point + 1];
    for (int i = 0; i < len - 1; i++)
    {
        list[++point] = cache[len - 1 - i];
        list.insert(list.begin()+(++point),cache[0]);
    }
    list.erase(list.begin() + (++point));
    list.erase(list.begin() + point--);
}