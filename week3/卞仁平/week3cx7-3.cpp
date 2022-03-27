#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    long long a[36];
    a[1]=2;
    int i;
    for(i=2;i<=35;i++)a[i]=3*(1+a[i-1])-1;
    while(cin>>n)cout<<a[n]<<endl;
    return 0;
}