#include <iostream>
using namespace std;
long long sum=0;
void hannuota(int);
main()
{
    int n;
    while (cin>>n)
    {
        long long a[n];
        a[0] = 2;
        for (int i = 1; i < n;i++)
        {
            a[i] = a[i - 1] * 3 + 2;
        }
        cout << a[n - 1]<<endl;
   }
}
