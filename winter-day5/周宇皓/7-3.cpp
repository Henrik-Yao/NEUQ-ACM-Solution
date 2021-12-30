#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> m;
ll n,x;
vector<ll> v;
int main()
{
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        if(m[x]==0)
        {
            m[x]=1;
            v.push_back(x);
        }
    }
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        if(m[x]==0)
        {
            m[x]=1;
            v.push_back(x);
        }
    }
    sort(v.begin(),v.end());
    cout<<v[(v.size()-1)/2]<<endl;
    return 0;
}
