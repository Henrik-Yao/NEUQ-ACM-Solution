#include<bits/stdc++.h>
using namespace std;

bool Check(int n)
{
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return 0;
    return 1;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        if(n % 2 == 0) {puts("2"); continue;}
        if(Check(n)) {puts("1"); continue;}
        if(Check(n - 2)) {puts("2"); continue;}
        puts("3");
    }
    return 0;
}