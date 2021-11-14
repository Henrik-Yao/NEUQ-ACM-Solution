#include<bits/stdc++.h>
using namespace std;
bool oshu(int x)
{
    if(x%2==0)return 1;
    else return 0;
}
bool is(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        if(oshu(x))
        {
            cout<<2<<endl;
            continue;
        }
        if(is(x))
        {
            cout<<1<<endl;
            continue;
        }
        if(is(x-2))
        {
            cout<<2<<endl;
            continue;
        }
        cout<<3<<endl;
        
    }
    return 0;
}