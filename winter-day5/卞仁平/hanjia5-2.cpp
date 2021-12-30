#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<n+n;i++)
    cin>>a[i];
    sort(a,a+2*n);
    cout<<a[n-1];
    return 0;

}