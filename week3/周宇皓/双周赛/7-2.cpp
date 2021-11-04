#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string a,b,c;
void dfs(ll n,string a,string b,string c)
{
    if(n==1)
    {
        cout<<a<<"->"<<c<<endl;
        return ;
    }
    dfs(n-1,a,c,b);
    cout<<a<<"->"<<c<<endl;
    dfs(n-1,b,a,c);
}
int main()
{
    cin>>n;
    cin>>a>>b>>c;
    dfs(n,a,b,c);
    return 0;
}
