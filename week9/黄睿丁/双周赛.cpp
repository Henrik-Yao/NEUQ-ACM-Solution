#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[n-1];
    int i,j;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        b[i]=a[i+1]-a[i]-1;
    }
    int len=n;
    sort(b,b+n-1);
    for(i=0;i<n-m;i++)
        len+=b[i];
    cout<<len;
}