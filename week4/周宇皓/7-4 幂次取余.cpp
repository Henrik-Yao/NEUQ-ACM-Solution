#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,t;
ll powe(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b%2) res=res*a%c;
        a=a*a%c;
        b/=2;
    }
    return res%c;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        cout<<powe(a,b,c)<<endl;
    }
    return 0;
}
