#include <iostream>
#include<algorithm>
using namespace std;
int a[100];
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int lsz;
        cin >> lsz;
        a[lsz]++;
    }
    for (int i = 0; i < 100; i++)
    {
        if (a[i])
            cout << i << ":" << a[i] << endl;
    }
    return 0;
}