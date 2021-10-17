#include <iostream>
using namespace std;
struct stu
{
    int fx;
    string name;
};
struct sign
{
    int zy;
    int no;
};

main()
{
    int n, m;
    cin >> n >> m;
    stu s[n];
    sign x[m];
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].fx >> s[i].name;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x[i].zy >> x[i].no;
    }
    for (int i = 0; i < m; i++)
    {

        if (x[i].zy == s[num].fx)
        {
            num = num - x[i].no;
            while (num < 0)
            {
                num = n + num;
            }
            while (num >= n)
            {
                num = num - n;
            }
        }
        else if (x[i].zy != s[num].fx)
        {
            num = num + x[i].no;
            while (num < 0)
            {
                num = n + num;
            }
            while (num >= n)
            {
                num = num - n;
            }
        }
    }
    cout << s[num].name;
}
