#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        if (n == 1)cout << 1 << endl;
        else if (n == 2)cout << 2 << endl;
        else if (n == 3)cout << 4 << endl;
        else {
            long long f1 = 1, f2 = 2, f3 = 4, f4 = f1;
            while (n > 3) {
                f4 = f1 + f2 + f3;
                f1 = f2;
                f2 = f3;
                f3 = f4;
                n--;
            }
            cout << f4 << endl;
        }
    }
}