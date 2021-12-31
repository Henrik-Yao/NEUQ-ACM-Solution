#include <iostream>
using namespace std;
int a[1000];
int main()
{
   
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
                int lsz = a[i];
                for (k = i - 1; k > j; k--)
                    a[k + 1] = a[k];
                a[k + 1] = lsz;
            }
            for (int i = 0; i < num - 1; i++)
                cout << a[i] << " ";
            cout << a[num - 1] << endl;
        }
    }
    return 0;
}