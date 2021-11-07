#include<iostream>
using namespace std;

const int Max = 10000001;
int group[Max];
long long int n;

int main() {
    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        if (i % 2)
        {
            group[i] = 0;
        }
        else
        {
            group[i] = 1;
        }
    }
    for (int i = 3; i * i <= n; i++)
    {
        if (!group[i])
        {
            for (int j = i + i; j <= n; j += i)
            {
                group[j] = 1;
            }
        }
    }

    int result = 0;

    for (int i = 2; i <= n; i++)
    {
        if (!group[i]) {
            result++;
        }
    }
    cout << result << endl;

    return 0;
}
