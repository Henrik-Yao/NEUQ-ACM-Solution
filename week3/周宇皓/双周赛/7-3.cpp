#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll power(ll a,ll m)
{
    ll res=1;
    while(m)
    {
        if(m%2==1) res*=a;
        a=a*a;
        m/=2;
    }
    return res;
}
int main()
{
    while(cin>>n)
    {
        cout<<(power(3,n)-1)<<endl;
    }
    return 0;
}
