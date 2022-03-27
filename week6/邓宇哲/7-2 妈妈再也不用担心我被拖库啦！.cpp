#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, string> user;
set<long> hashs;
long hashy(string);
main()
{
    int n;
    cin >> n;
    char func;
    string name, password;
    for (int i = 0; i < n; i++)
    {
        cin >> func >> name >> password;
        if (func == 'R')
        {
            if (user.find(name) != user.end())
            {
                cout << "Repeated!" << endl;
                continue;
            }
            else
            {
                user[name] = password;

                cout << "Signed!" << endl;
                hashs.insert(hashy(password));
                continue;
            }
        }
        if (func == 'L')
        {
            if (user.find(name) == user.end())
            {
                cout << "Failed!" << endl;
                continue;
            }
            if (user[name] == password)
            {
                cout << "Success!" << endl;
            }
            else
            {
                if (hashs.count(hashy(password)))
                {
                    cout << "Attention!" << endl;
                    continue;
                }
                else
                    cout << "Failed!" << endl;
            }
        }
    }
}
long hashy(string a) //先录入密码再进行哈希
{

    int point = 0;
    int hashcache[4] = {0}, data[4];
    int l = a.length();
    long hashhash = 0;
    for (int i = 0; i < l; i++)
    {
        if (a[i] <= 'Z' && a[i] >= 'A')
        {
            a[i] = a[i] - 'A' + 10;
        }
        if (a[i] <= 'z' && a[i] >= 'a')
        {
            a[i] = a[i] - 'a' + 10;
        }
        if (a[i] <= '9' && a[i] >= '0')
        {
            a[i] = a[i] - '0';
        }
    }
    int mod = l % 4, wide = l / 4;
    for (int i = 0; i < 4; i++)
    {
        if (mod != 0)
        {
            data[i] = wide + 1;
            mod--;
        }
        else
        {
            data[i] = wide;
        }
    }
    for (int i = 0; i < data[0]; i++)
    {
        hashcache[0] = hashcache[0] + a[point++];
    }
    data[0] = hashcache[0] % 36;
    for (int i = 0; i < data[1]; i++)
    {
        hashcache[1] = hashcache[1] + a[point++];
    }
    data[1] = hashcache[1] % 36;
    for (int i = 0; i < data[2]; i++)
    {
        hashcache[2] = hashcache[2] + a[point++];
    }
    data[2] = hashcache[2] % 36;
    for (int i = 0; i < data[3]; i++)
    {
        hashcache[3] = hashcache[3] + a[point++];
    }
    data[3] = hashcache[3] % 36;
    for (int i = 0; i < 4; i++)
    {
        hashhash = hashhash * 36 + data[i];
    }
    return hashhash;
}