#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[10005];

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int sum=0,maxi=0;

    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum<0)
            sum=0;
        if(sum>maxi)
            maxi = sum;
    }

    cout<<maxi;


    return 0;
}
