#include <bits/stdc++.h>
using namespace std;
long long a[1000100];
int n, l=0, r, mid;
long long w;
int main(void)
{
    
    cin>>n>>w;
    
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    r=n-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]>=w)
            r=mid-1;
        else
            l=mid+1;
    }
    l++;
    cout<<l;
    
    return 0;
}