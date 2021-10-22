#include<bits/stdc++.h>
using namespace std;
int main()
{
	int p = 0;
    int n;
    string a;
    cin >> n;
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        int sum = 0;
        int len1 = c.length(), len2 = a.length();
        int t = 0;
        for (int p = 0; p < len2;)
        {
            if (c[t] == a[p])
            {
                if (t == len1 - 1)
                {
                    sum++;
                    p = p - len1+2;
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
    }
}
