#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long f[55];
    int n,t;

    f[1]=0;
    f[2]=1;
    f[3]=2;
    for(int i=4;i<50;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }

    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }

    return 0;
}
