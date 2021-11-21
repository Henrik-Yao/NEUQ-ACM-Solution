#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int x=0,y=0;
    for(i=0;i<n;i++)
    {
        if(x>=0)
            x+=a[i];
            else
                x=a[i];
        if(x>y)
            y=x;
    }
    cout<<y;
}
