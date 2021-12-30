#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    while(cin>>n)
    {
    int a[n],t;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++)
    {
        t=a[i];
        int j;
        for(j=i-1;j>=0&&t<a[j];j--)
        a[j+1]=a[j];
        a[j+1]=t;
        for(int k=0;k<n;k++)
        {
            cout<<a[k];
            if(k!=n-1) cout<<" ";
        }
        cout<<endl;
    }
    }
    return 0;
}
