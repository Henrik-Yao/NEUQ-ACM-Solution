#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    long long t, a, b, c;
    cin >> t;
    for (int qwer = 0; qwer < t; qwer++)
    {
        cin >> a >> b >> c;
        long long sum = 1;
        while (b)
        {
            if (b % 2 == 1) 
            {
                b = b - 1;
                sum = sum * a % c;
            }
                b = b / 2;
                a = a * a % c;
        }
        cout << sum << endl;
    }
}