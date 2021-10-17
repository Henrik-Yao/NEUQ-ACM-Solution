#include <iostream>
#include <cstring>
using namespace std;
int shun[1100000], ni[1100000], sign[110000], a[1100000];
main()
{

    int n, j = 0,biggest=-1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!sign[a[i]])
        {
            j++;
        }
        shun[i] = j;
        sign[a[i]] = 521;
    }
    memset(sign, 0, sizeof(sign));
    int k = 1;
    sign[a[n]] = 1;
    ni[n] = 1;
    for (int i = n-1; i > 0;i--)
    {
        if(!sign[a[i]])
        {
            k++;
        }
        sign[a[i]] = 520;
        ni[i] = k;
        biggest = max((shun[i] + ni[i+1]), biggest);
    }
    cout << biggest;
}
