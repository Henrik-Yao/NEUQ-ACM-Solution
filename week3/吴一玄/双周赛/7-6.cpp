#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    char s[20];
    cin >> s + 1;
    int n = strlen(s + 1);
    sort(s + 1, s + 1 + n);
    do
    {
        cout << s + 1 << "\n";
    }while(next_permutation(s + 1, s + 1 + n));
}