#include <bits/stdc++.h>
using namespace std;

int main()
{
    struct dish{
    int v;
    int t;
    };

    int n,T;
    cin>>n>>T;

    dish a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i].v>>a[i].t;
    }

    for(int i=0;i<n;i++)
    {
        if(a[i].t>T)
            a[i].v -= (a[i].t-T);
    }

     int maxi = a[0].v;
     for(int i=1;i<n;i++)
    {
        if(a[i].v>maxi)
            maxi = a[i].v;
    }

    cout<<maxi;


    return 0;
}
