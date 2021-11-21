#include <iostream>
using namespace std;
main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n1;
        cin >> n1;
        int a[n1];
        for (int p = 0; p < n1; p++)
        {
            cin >> a[p];
        }
        int n2;
        cin >> n2;
        int b[n2];
        for (int p = 0; p < n2; p++)
        {
            cin >> b[p];
        }
        int j = 0, k = 0, out[n1 + n2];
        for (int p = 0; p < n1 + n2;p++)
        {
            if (a[j] > b[k])
            {
                out[p] = b[k];
                k++;
            }
            else {
                out[p] = a[j];
                j++;
            }

        }
        for (int p = 0; p < n1 + n2-1;p++ )
        {
            cout << out[p] << ' ';
        }
        cout << out[n1 + n2 - 1] << endl;
    }
}
