#include <iostream>
#include <map>
using namespace std;
map<string, string> dic;
main()
{
    int n, m;
    string origin, target;
    string wanted;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        cin >> target >> origin;
        dic[origin] = target;
    }
    for (int i = 0; i < m;i++)
    {
        cin >> wanted;
        if(dic.find(wanted)==dic.end())
        {
            cout << "eh" << endl;
            continue;
        }
        cout << dic[wanted] << endl;
    }
}