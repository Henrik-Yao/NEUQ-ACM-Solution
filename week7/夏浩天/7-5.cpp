#include <iostream>
#include<string.h>
using namespace std;
int n, m;
int weight[10000], value[10000], f[10000];
int main()
{
    while (cin >> n >> m)
    {
        memset(weight, 0, 10000);
        memset(value, 0, 10000);
        memset(f, 0, 10000);
        for (int i = 0; i < n; i++) 
            cin >> weight[i];
        for (int i = 0; i < n; i++) 
            cin >> value[i];
        for (int i = 0; i < n; i++) 
        {
            for (int j = m; j >= weight[i]; j--)
                f[j] = max(f[j], f[j - weight[i]] + value[i]);
        }
        cout << f[m] << endl;
    }
}