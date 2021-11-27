#include<iostream>
using namespace std;

const int N = 1010;
int t;
int q[N], f[N];

int main()
{
    cin >> t;
    int x = t;
    while (x--)
    {
        if (x != t - 1)
        {
            cout << endl;
        }
        int n;
        cin>>n;
        for (int i = 1; i <= n; i++)
        {
            cin>>q[i], f[i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (q[j] < q[i])
                {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        int a = -1;
        for (int i = 1; i <= n; i++)
        {
            a = max(a, f[i]);
        }
        cout<<a<<endl;
    }
    return 0;
}