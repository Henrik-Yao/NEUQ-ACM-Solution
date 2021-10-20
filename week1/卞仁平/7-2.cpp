#include <bits/stdc++.h>
using namespace std;
int n;
int ss,s1=0,s2=0;
bool b1[1000001],b2[1000001];
int a[1000001],x1[1000001],x2[1000001];
int main()
{
    cin>>n;
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)
    {
        if(b1[a[i]]==0)
        {
            b1[a[i]]=1;
            s1++;
        }
        x1[i]=s1;
    }

    for(i=n-1;i>=0;i--)
    {
        if(b2[a[i]]==0)
        {
            b2[a[i]]=1;
            s2++;
        }
        x2[i]=s2;
        ss=max(ss,x1[i]+x2[i+1]);
    }
    cout<<ss;
    return 0;

}