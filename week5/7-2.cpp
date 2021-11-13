#include<iostream>
using namespace std;

bool prime(int n)
{
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return 0;
    return 1;
}

int main()
{
    int N; 
    cin>>N;
    while(N--)
    {
        int n; 
        cin>>n;
        if(n % 2 == 0) 
        {
            puts("2"); continue;
            }
        if(prime(n)) 
        {
            puts("1"); 
                continue;
        }
        if(prime(n - 2)) 
        {
            puts("2"); 
                continue;
        }
            puts("3");
    }
    return 0;
}