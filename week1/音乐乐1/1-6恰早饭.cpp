#include<iostream>
using namespace std;

int main()
{
    int n,T,i,max=-999999;
    cin>>n>>T;
    while(n--)
    {
        int v,t,ans;
        cin>>v>>t;
        if(t>T)
            ans=v-(t-T);
        else
            ans=v;
        if(ans>max)
            max=ans;
    }
    cout<<max;
    return 0;
}
