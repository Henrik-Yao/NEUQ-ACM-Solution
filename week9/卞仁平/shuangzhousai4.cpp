#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    int b[n];
    for(int i=0;i<n/1;i++)
    b[i]=a[i+1]-a[i]-1;
    int s;
    s=a[n-1]-a[0]+1;
    sort(b,b+n-1);
    for(int i=0;i<m-1;i++)
    s-=b[n-2-i];
    cout<<s;
    return 0;

}
