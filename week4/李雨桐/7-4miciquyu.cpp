#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll mod(ll a,ll b,ll c )
{
    ll ans =1;

    if(b==0)
        ans = 1%c;

    while(b)
    {
        if(b%2==1)
            ans = a*ans%c;
        b/=2;
        a = (a*a)%c;
    }

    return ans;
}

int main()
{
    ll t,a,b,c;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        cout<<mod(a,b,c)<<endl;

    }

    return 0;
}
