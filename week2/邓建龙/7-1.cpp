#include <iostream>

using namespace std;

void func(int n, char a[], char b[], char c[])
{
    // 递归尽头
    if (n == 1) {
        printf("%s->%s\n", a, c);
    } else {
        // 如果有两个 1号放到 b 盘 2 号放到 c 盘 1 号从 b 盘放到 c 盘
        func(n - 1, a, c, b);
        printf("%s->%s\n", a, c);
        func(n - 1,b,a,c);
    }
}

int main()
{
    int n;
    cin >> n;
    char a[233],b[233],c[233];
    cin >> a >> b >> c;
    func(n,a,b,c);
    return 0;
}

