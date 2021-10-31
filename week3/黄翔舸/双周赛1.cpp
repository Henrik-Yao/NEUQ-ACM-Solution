
#include<iostream>
using namespace std;


int main()
{
    int n;
    int num[1001];
    int i, j, k;
    int sum, max;
    while (cin >> n)
    {
        for (i = 0; i < n; i++)
            cin >> num[i];
        max = 0;
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = i; j < n; j++)
            {
                sum += num[j];
                if (sum > max)
                    max = sum;
            }
        }
        cout << max;
    }
    return 0;
}
