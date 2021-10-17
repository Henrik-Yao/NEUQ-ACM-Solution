#include <iostream>
using namespace std;
int p = 0;
main()
{
    int n;
    string a;
    cin >> n;
    cin >> a;

    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        int sum = 0;
        int lc = c.length(), la = a.length();
        int t = 0;
        for (int p = 0; p < la;)
        {
            
            if (c[t] == a[p])
            {
                if (t == lc - 1)
                {
                    sum++;
                    p = p - lc+2;
                    t = 0;
                }
                else
                {
                    p++;
                    t++;
                }
            }
            else
            {
                p = p - t+1;
                t = 0;
            }
        }
        cout << sum << endl;
        sum = 0;
    }
}
