#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int loca,p;
    p=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=m)
        {
            loca=i+1;
            p++;
            break;
        }
    }
    if(p==0)
    {
        loca=n+1;
    }
    cout<<loca;
    return 0;
}
