#include <iostream>

using namespace std;

int a[10000020]={0};

int main()
{
    int n, sum=0;
    cin >> n;
    a[1] = a[0] = 1;
    for(int i = 2; i * i < n; i++) {
        if(a[i] == 0){
            for(int j = 2 * i; j <= n; j += i) {
                a[j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}

