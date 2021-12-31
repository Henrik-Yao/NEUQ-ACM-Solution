#include <bits/stdc++.h>
using namespace std;
//²åÈëÅÅÐò£¬´òÓ¡Â·¾¶
int main()
{
    int a[1000];
    int num;
    while (cin >> num)
    {
        for (int i = 0; i < num; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < num; i++)
        {
            int j, k;
            for (j = i - 1; j >= 0; j--)
                if (a[j] < a[i])
                    break;
            if (j != i - 1)
            {
                int remp = a[i];
                for (k = i - 1; k > j; k--)
                    a[k + 1] = a[k];
                a[k + 1] = remp;
            }
            for (int i = 0; i < num - 1; i++)
                cout << a[i] << " ";
            cout << a[num - 1] << endl;
        }
    }

    return 0;
}