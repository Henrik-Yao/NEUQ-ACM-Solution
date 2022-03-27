#include <iostream>
using namespace std;
typedef long long ll;
ll mod(ll a,ll b,ll c);
int main()
{
    ll t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        ll s,a,b,c;
        cin>>a>>b>>c;
        s=mod(a,b,c);
        cout<<s<<endl;
    }
    
}

ll mod(ll a,ll b,ll c)
{
    if(b==1)
        return a%c;
    ll x,y;
    if(b%2==0)
    {
        x=mod(a,b/2,c);
        x*=x;
        x=x%c;
        return x;
    }
    else
    {
        x=mod(a,b/2,c);
        y=mod(a,b/2+1,c);
        x*=y;
        x=x%c;
        
        return x;
    }
    
}
