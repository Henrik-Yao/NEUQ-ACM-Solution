#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m;
    cin>>n;
    int a[41];
    a[0]=0;a[1]=1;a[2]=2;
    for(int i=3;i<=41;i++)
    a[i]=a[i-1]+a[i-2];
    while(n--)
    {
        cin>>m;
        cout<<a[m-1]<<endl;
    }
    return 0;
}