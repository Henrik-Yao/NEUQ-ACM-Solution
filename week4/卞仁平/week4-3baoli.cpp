#include <bits/stdc++.h>
using namespace std;
#define int long long 
//方法一：暴力筛超时
bool baoli(int n);
signed main()
{
    int n;
    cin>>n;
    if(n==1)cout<<0;
    else if(n==2)cout<<1;
    else
    {
    int s=1;
    for(int i=3;i<=n;i++)
    if(baoli(i))s++;
    cout<<s;
    }
    return 0;
}
bool baoli(int n)
{
    int i;
    bool f=1;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            f=0;
            break;
        }
    }
    if(f)return true;
    else return false;
}