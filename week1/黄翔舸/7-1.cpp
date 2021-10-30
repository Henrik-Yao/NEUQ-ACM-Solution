#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int l = 4e6;
char str[l];
string a;
int n, m;
int main()
{
    cin >> n >> str + 1;
    int q = strlen(str + 1);
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        cin >> a;
        int len = a.length();
        for (int i = 1; i <= q - len + 1; i++)
        {
            string b;
            b.clear();
            for (int j = i; j <= i + len - 1; j++)
                b = b + str[j];
            if (a == b)
                ++num;
        }
        cout << num;
        if (i != n) cout << "\n";
    }
    return 0;
}