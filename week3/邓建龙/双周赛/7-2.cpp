#include <iostream>

using namespace std;

void func(int n, char a[], char b[], char c[])
{
    if (n == 1) printf("%s->%s\n", a, c);
    else {
        func(n - 1, a, c, b);
        printf("%s->%s\n", a, c);
        func(n - 1, b ,a, c);
    }
}

int main()
{
    int n;
    char a[30],b[30],c[30];
    cin >> n >> a >> b >> c;
    func(n, a, b, c);
    return 0;
}