#include <bits/stdc++.h>
using namespace std;

long long f(int n)
{
    if(n==1)
        return 2;
    else
    {
        return 3*f(n-1)+2;
    }
}

int main()
{
    int n;
    long long ans;
    while(cin>>n)
    {
       cout<<f(n)<<endl;
    }


    return 0;
}
