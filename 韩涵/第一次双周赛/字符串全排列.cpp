#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
    char a[9];
    cin >> a;
    int n = strlen(a);
    sort(a, a + n); 
    do{
        for (int i = 0; i < n; i++) cout << a[i];
        cout << endl;
    } while (next_permutation(a, a + n));
}