#include <iostream>  
#include <string.h>  
using namespace std;

int main() {
    int a[10005], i;
    memset(a, 0, sizeof(int) * 10005);
    int n;
    cin >> n;
    int num, count = 0;
    for (i = 0; i < n; i++) {
        cin >> num;
        a[num]++;
    }
    for (i = 0; i < 10004; i++) {
        if (a[i] && a[i + 1])
            count++;
    }
    cout << count << endl;
    return 0;
}