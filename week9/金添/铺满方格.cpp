#include <bits/stdc++.h>
using namespace std;
long long a[51];
long long ans(long long n)//¾­µäµÝ¹éÎÊÌâ
{
    if(a[n])
    return a[n];
    else if(n==1)
    return a[1]=1;
    else if(n==2)
    return a[2]=2;
    else if(n==3)
    return a[3]=4;
    else
    return a[n]=ans(n-1)+ans(n-2)+ans(n-3);
}
int main()
{
    long long n;
    while(cin>>n)
    {
        cout<<ans(n)<<endl;
    }
    return 0;
}
