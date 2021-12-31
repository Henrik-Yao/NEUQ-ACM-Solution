#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
int main()
{
    char zimu[9];
    cin >> zimu;
    int n = strlen(zimu);

    sort(zimu, zimu + n);
    do
    {
        for (int i = 0; i < n; i++)
            cout << zimu[i];
        cout << endl;
    } while (next_permutation(zimu, zimu + n));
    return 0;
}