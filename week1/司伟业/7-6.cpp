#include<iostream>
using namespace std;

int n,t,aa,bb,ans=-2000000000;

int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>aa>>bb;
        if(bb<=t)ans=max(ans,aa);
        else ans=max(ans,aa+t-bb);
    }
    cout<<ans;
}
